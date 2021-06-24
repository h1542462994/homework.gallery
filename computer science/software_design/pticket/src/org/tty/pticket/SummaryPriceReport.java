package org.tty.pticket;

public class SummaryPriceReport implements Observer<Double> {
    private boolean firstInit = true;
    private double min;
    private double max;
    private int tick;
    private double sum;

    @Override
    public void onDataChanged(Double data) {
        if (firstInit) {
            firstInit = false;
            min = data;
            max = data;
            tick = 1;
            sum = data;
        } else {
            min = Math.min(data, min);
            max = Math.max(data, max);
            tick++;
            sum+= data;
        }

        System.out.println("历史股票最高价:" + max
            + ", 历史股票最低价:" + min
            + ", 历史股票均价:" + Math.round(sum / tick * 100) / 100.0
        );
    }
}
