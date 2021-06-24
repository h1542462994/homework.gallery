package org.tty.pcard;

import java.io.File;
import java.io.FileFilter;
import java.io.IOException;
import java.net.JarURLConnection;
import java.net.URL;
import java.net.URLDecoder;
import java.util.Enumeration;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.function.Predicate;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;

/**
 * class 扫描器
 *
 * @author zhangyunan
 */
public class ClassScanner {

    private final String basePackage;
    private final boolean recursive;
    private final Predicate<String> packagePredicate;
    private final Predicate<Class<?>> classPredicate;


    /**
     * Instantiates a new Class scanner.
     *
     * @param basePackage   the base package
     * @param recursive    是否递归扫描
     * @param packagePredicate the package predicate
     * @param classPredicate  the class predicate
     */
    public ClassScanner(String basePackage, boolean recursive, Predicate<String> packagePredicate,
                        Predicate<Class<?>> classPredicate) {
        this.basePackage = basePackage;
        this.recursive = recursive;
        this.packagePredicate = packagePredicate;
        this.classPredicate = classPredicate;
    }

    /**
     * Do scan all classes set.
     *
     * @return the set
     * @throws IOException      the io exception
     * @throws ClassNotFoundException the class not found exception
     */
    public Set<Class<?>> doScanAllClasses() throws IOException, ClassNotFoundException {

        Set<Class<?>> classes = new LinkedHashSet<Class<?>>();

        String packageName = basePackage;

        // 如果最后一个字符是“.”，则去掉
        if (packageName.endsWith(".")) {
            packageName = packageName.substring(0, packageName.lastIndexOf('.'));
        }

        // 将包名中的“.”换成系统文件夹的“/”
        String basePackageFilePath = packageName.replace('.', '/');

        Enumeration<URL> resources = Thread.currentThread().getContextClassLoader().getResources(basePackageFilePath);
        while (resources.hasMoreElements()) {
            URL resource = resources.nextElement();
            String protocol = resource.getProtocol();
            if ("file".equals(protocol)) {
                String filePath = URLDecoder.decode(resource.getFile(), "UTF-8");
                // 扫描文件夹中的包和类
                doScanPackageClassesByFile(classes, packageName, filePath);
            } else if ("jar".equals(protocol)) {
                doScanPackageClassesByJar(packageName, resource, classes);
            }
        }

        return classes;
    }

    private void doScanPackageClassesByJar(String basePackage, URL url, Set<Class<?>> classes)
            throws IOException, ClassNotFoundException {
        // 包名
        String packageName = basePackage;
        // 获取文件路径
        String basePackageFilePath = packageName.replace('.', '/');
        // 转为jar包
        JarFile jar = ((JarURLConnection) url.openConnection()).getJarFile();
        // 遍历jar包中的元素
        Enumeration<JarEntry> entries = jar.entries();
        while (entries.hasMoreElements()) {
            JarEntry entry = entries.nextElement();
            String name = entry.getName();
            // 如果路径不一致，或者是目录，则继续
            if (!name.startsWith(basePackageFilePath) || entry.isDirectory()) {
                continue;
            }
            // 判断是否递归搜索子包
            if (!recursive && name.lastIndexOf('/') != basePackageFilePath.length()) {
                continue;
            }

            if (packagePredicate != null) {
                String jarPackageName = name.substring(0, name.lastIndexOf('/')).replace("/", ".");
                if (!packagePredicate.test(jarPackageName)) {
                    continue;
                }
            }

            // 判定是否符合过滤条件
            String className = name.replace('/', '.');
            className = className.substring(0, className.length() - 6);
            // 用当前线程的类加载器加载类
            Class<?> loadClass = Thread.currentThread().getContextClassLoader().loadClass(className);
            if (classPredicate == null || classPredicate.test(loadClass)) {
                classes.add(loadClass);
            }

        }
    }

    /**
     * 在文件夹中扫描包和类
     */
    private void doScanPackageClassesByFile(Set<Class<?>> classes, String packageName, String packagePath)
            throws ClassNotFoundException {
        // 转为文件
        File dir = new File(packagePath);
        if (!dir.exists() || !dir.isDirectory()) {
            return;
        }
        // 列出文件，进行过滤
        // 自定义文件过滤规则
        File[] dirFiles = dir.listFiles((FileFilter) file -> {
            String filename = file.getName();

            if (file.isDirectory()) {
                if (!recursive) {
                    return false;
                }

                if (packagePredicate != null) {
                    return packagePredicate.test(packageName + "." + filename);
                }
                return true;
            }

            return filename.endsWith(".class");
        });

        if (null == dirFiles) {
            return;
        }

        for (File file : dirFiles) {
            if (file.isDirectory()) {
                // 如果是目录，则递归
                doScanPackageClassesByFile(classes, packageName + "." + file.getName(), file.getAbsolutePath());
            } else {
                // 用当前类加载器加载 去除 fileName 的 .class 6 位
                String className = file.getName().substring(0, file.getName().length() - 6);
                Class<?> loadClass = Thread.currentThread().getContextClassLoader().loadClass(packageName + '.' + className);
                if (classPredicate == null || classPredicate.test(loadClass)) {
                    classes.add(loadClass);
                }
            }
        }
    }
}
