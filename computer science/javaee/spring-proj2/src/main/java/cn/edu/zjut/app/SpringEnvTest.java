package cn.edu.zjut.app;

import cn.edu.zjut.bean.ItemOrder;
import org.springframework.beans.factory.support.DefaultListableBeanFactory;
import org.springframework.beans.factory.xml.XmlBeanDefinitionReader;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.context.support.FileSystemXmlApplicationContext;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.FileSystemResource;

public class SpringEnvTest {
    public static void main(String[] args){
        SpringEnvTest test = new SpringEnvTest();
        test.run();
    }
    public void run(){
//        System.out.println("===calling withFileSystemResource()===");
//        withFileSystemResource();
//        System.out.println("===calling withClassPathResource()===");
//        withClassPathResource();
//        System.out.println("===calling withFileSystemApplicationContext()===");
//        withFileSystemApplicationContext();
        System.out.println("===calling withClassPathApplicationContext()===");
        withClassPathApplicationContext();
    }
    public void withFileSystemResource() {
        FileSystemResource resource = new FileSystemResource("src/main/resources/applicationContext.xml");
        DefaultListableBeanFactory factory = new DefaultListableBeanFactory();
        new XmlBeanDefinitionReader(factory).loadBeanDefinitions(resource);
        ItemOrder itemOrder1 = (ItemOrder) factory.getBean("itemOrder1");
    }
    public void withClassPathResource() {
        ClassPathResource resource = new ClassPathResource("applicationContext.xml");
        DefaultListableBeanFactory factory = new DefaultListableBeanFactory();
        new XmlBeanDefinitionReader(factory).loadBeanDefinitions(resource);
        ItemOrder itemOrder1 = (ItemOrder) factory.getBean("itemOrder1");
    }
    public void withFileSystemApplicationContext() {
        AbstractApplicationContext context = new FileSystemXmlApplicationContext("src/main/resources/applicationContext.xml");
        ItemOrder itemOrder1 = (ItemOrder) context.getBean("itemOrder1");
        context.registerShutdownHook();
    }
    public void withClassPathApplicationContext() {
        AbstractApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
        ItemOrder itemOrder1 = (ItemOrder) context.getBean("itemOrder1");
        context.registerShutdownHook();
    }
}
