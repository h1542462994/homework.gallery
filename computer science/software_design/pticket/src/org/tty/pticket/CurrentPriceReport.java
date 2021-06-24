package org.tty.pticket;

public class CurrentPriceReport implements Observer<Double> {
    private Double price;

    @Override
    public void onDataChanged(Double data) {
        price = data;
        System.out.println("当前股票交易价:" + price);
    }
}
