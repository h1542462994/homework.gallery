package org.tty.pticket;

public class PredictPriceReport implements Observer<Double> {
    private boolean firstInit = true;
    private double current;

    @Override
    public void onDataChanged(Double data) {
        double prev;
        if (firstInit) {
            firstInit = false;
            prev = data;
        } else {
            prev = current;
        }
        current = data;

        double predict = current + 0.6 * (current - prev);
        System.out.println("下次股票价格预测:" + Math.round(predict * 100) / 100.0);
    }
}
