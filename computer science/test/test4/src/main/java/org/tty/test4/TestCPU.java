package org.tty.test4;

import java.util.ArrayList;

public class TestCPU {

    public static ArrayList<Thread> threadList = new ArrayList<Thread>();

    public static void testCPU() throws Exception {

        Thread thread = new Thread(new CPUControlInSinShape());

        threadList.add(thread);
        thread.start();
    }

    @SuppressWarnings("deprecation")
    public static void free(Thread thread) {
        thread.stop();
    }

}

class CPUControlInSinShape implements Runnable {

    final double SPLIT = 0.01;
    final int COUNT = (int) (2 / SPLIT);
    final double PI = Math.PI;
    final int INTERVAL = 250;
    long[] busySpan = new long[COUNT];
    long[] idleSpan = new long[COUNT];
    int half = INTERVAL / 2;
    double radian = 0.0;

    public void run() {
        for (int i = 0; i < COUNT; i++) {
            busySpan[i] = (long) (half + (Math.sin(PI * (radian - 0.5)) * half));
            idleSpan[i] = INTERVAL - busySpan[i];
            radian += SPLIT;
        }

        long startTime = 0;
        int j = 0;

        while (true) {
            j = j % COUNT;

            startTime = System.currentTimeMillis();

            while ((System.currentTimeMillis() - startTime) < busySpan[j]) {}

            try {
                Thread.sleep(idleSpan[j]);
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }

            j++;
        }

    }
}
