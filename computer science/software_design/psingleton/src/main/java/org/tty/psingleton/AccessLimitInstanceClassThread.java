package org.tty.psingleton;

import java.util.Random;

public class AccessLimitInstanceClassThread extends Thread {


    @Override
    public void run() {
        try {
            LimitInstanceClass instance = null;
            do {
                instance = LimitInstanceClass.getInstance();
                //printStart(instance);
                if (instance != null) {
                    instance.writeAccessMessage(String.valueOf(this.getId()));
                }
                Random random = new Random();
                long sleepTime = (long) (5000 * random.nextDouble());

                Thread.sleep(sleepTime);
                if (instance != null) {
                    instance.printAccessMessage();
                    instance.release();
                }

            } while (instance == null);

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void printStart(LimitInstanceClass instanceClass) {
        if (instanceClass == null) {
            System.out.println(this.getId() + ":" + "not free instance.");
        } else {
            System.out.println(this.getId() + ":" + instanceClass.getId());
        }
    }
}
