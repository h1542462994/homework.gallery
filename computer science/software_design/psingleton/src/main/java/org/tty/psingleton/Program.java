package org.tty.psingleton;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Properties;

public class Program {

    public static void main(String[] args) throws IOException {
        Properties properties = new Properties();
        properties.load(ClassLoader.getSystemResourceAsStream("main.properties"));

        LimitInstanceClass.prepare(properties);

        //System.out.println(LimitInstanceClass.getInstanceLimit());

        ArrayList<Thread> threads = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            threads.add(new AccessLimitInstanceClassThread());
        }

        for (var thread : threads){
            thread.start();
        }
    }
}
