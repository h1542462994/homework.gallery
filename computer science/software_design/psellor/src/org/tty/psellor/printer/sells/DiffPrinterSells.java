package org.tty.psellor.printer.sells;

import org.tty.psellor.printer.PrinterPack;

public class DiffPrinterSells implements PrinterSells {
    public DiffPrinterSells(Double diff) {
        this.diff = diff;
    }

    private Double diff;

    public Double getDiff() {
        return diff;
    }

    public void setDiff(Double diff) {
        this.diff = diff;
    }


    @Override
    public Double totalPrize(Iterable<PrinterPack> printerPacks) {
        double totalPrize = 0.0;
        for (PrinterPack pack: printerPacks) {
            double newPrize = pack.getPrinter().prize() - diff;
            if (newPrize < 0) {
                newPrize = 0;
            }
            totalPrize += newPrize * pack.getCount();
        }
        return totalPrize;
    }
}
