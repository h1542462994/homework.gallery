package org.tty.test4;

import java.util.ArrayList;

public class TestMemory {
    public static ArrayList<Thread> threadList = new ArrayList<>();
    public static int fullCount = 0;
    public static int partCount = 0;

    public static void runFullCopy() {
        Thread thread = new Thread(new MemoryFullCopy());
        threadList.add(thread);
        thread.start();
        fullCount++;
    }

    public static void runPartCopy() {
        Thread thread = new Thread(new MemoryPartCopy());
        threadList.add(thread);
        thread.start();
        partCount++;
    }

    @SuppressWarnings("deprecation")
    public static void free(Thread thread) {
        thread.stop();
    }
}

class MemoryFullCopy implements Runnable {

    private byte[] memory;

    @Override
    public void run() {
        int size = 1024 * 1000;

        try {
            while(true) {
                memory = new byte[size];
                Thread.sleep(99);
                memory = null;
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}

class MemoryPartCopy implements Runnable {
    private byte[] memory;

    public void run() {
        int size = 1024;

        try {
            while (true) {
                memory = new byte[size];
                Thread.sleep(1);
                memory = null;
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}