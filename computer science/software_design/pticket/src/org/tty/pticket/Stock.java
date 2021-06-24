package org.tty.pticket;

import java.util.Random;

public class Stock implements Observable<Double> {
    private final ObserveData<Double> observeData = new ObserveData_Impl<>();
    private Thread ticketThread = null;

    private class TicketThread implements Runnable {
        private final Random random = new Random();

        @Override
        public void run() {
            try {
                while (!Thread.interrupted()) {
                    double ticketPrice = Math.round(random.nextDouble() * 2000000) / 100.0;
                    observeData.pushData(ticketPrice);
                    observeData.notifyDataChanged();
                    Thread.sleep(5000);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    public ObserveData<Double> observeData() {
        return observeData;
    }

    public void start() {
        ticketThread = new Thread(new TicketThread());
        ticketThread.start();
    }

    public void stop() {
        ticketThread.interrupt();
    }
}
