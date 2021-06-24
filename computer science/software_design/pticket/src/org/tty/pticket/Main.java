package org.tty.pticket;

import java.util.Scanner;
import java.util.concurrent.atomic.AtomicReference;

public class Main {

    public static void main(String[] args) {
        Stock stock = new Stock();
        AtomicReference<Integer> tick = new AtomicReference<>(0);

        CurrentPriceReport priceReport = new CurrentPriceReport();
        SummaryPriceReport summaryPriceReport = new SummaryPriceReport();
        PredictPriceReport predictPriceReport = new PredictPriceReport();

        stock.observe(data -> {
            System.out.println("----------第" + tick + "次交易-----------");
            tick.getAndSet(tick.get() + 1);
        });
        stock.observe(priceReport);
        stock.observe(summaryPriceReport);
        stock.observe(predictPriceReport);

        System.out.println("股票交易所开始运行.");
        stock.start();

        // hold the console
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();

        stock.removeObserver(priceReport);
        stock.removeObserver(summaryPriceReport);
        stock.removeObserver(predictPriceReport);
    }
}
