package exp6;

import java.io.*;
import java.nio.CharBuffer;

public class JReadTxt {
    public static void main(String[] arg) throws java.io.IOException{
        File currentDirectory = new File(".");
        System.out.println(">>>>>currentDirectory: " + currentDirectory.getCanonicalPath());

        File readFile = new File("./柳永宋词.txt");
        File writeFile = new File("./景庄婉约.txt");
        String find = "柳永";
        String toReplace = "景庄";
        int totalCount = 0;

        if(!readFile.exists()){
            System.out.println(">>>>>error: 没有找到[柳永宋词.txt]，请再检查一下。");
            return;
        }

        try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(readFile), "gbk"));
             BufferedWriter writer = new BufferedWriter(new FileWriter(writeFile))) {

            System.out.println("文档大小:" + readFile.length() + "B");

            System.out.println(">>>>>开始读取文本");

            String line;

            while (true) {
                line = reader.readLine();
                if (line == null) {
                    break;
                }

                for (int i = 0; i < line.length() - find.length() + 1; i++) {
                    String sub = line.substring(i, i + find.length());
                    if (sub.equals(find)) {
                        totalCount++;
                        i += find.length() - 1;
                    }

                }

                //System.out.println(line);

                String newLine = line.replace(find, toReplace);

                writer.write(newLine);
                writer.newLine();
                //System.out.println(newLine);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }



        System.out.println(">>>>>结束读取文本");

        System.out.println(String.format("%s出现了%s次",find,totalCount));
    }
}
