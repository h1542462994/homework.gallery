package org.tty.psellor.printer.sells;

import org.tty.psellor.printer.PrinterPack;

public class NoPrinterSells implements PrinterSells {
    @Override
    public Double totalPrize(Iterable<PrinterPack> printerPacks) {
        double totalPrize = 0.0;
        for (PrinterPack pack: printerPacks) {
            totalPrize += pack.getPrinter().prize() * pack.getCount();
        }
        return totalPrize;
    }
}
