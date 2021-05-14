package org.tty.psellor.printer.sells;

import org.tty.psellor.printer.PrinterPack;

public interface PrinterSells {
    Double totalPrize(Iterable<PrinterPack> printerPacks);
}
