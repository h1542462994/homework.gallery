package org.tty.psellor.printer.formater;

import org.tty.psellor.printer.PrinterPack;

public interface PrinterFormatter {
    String format(Iterable<PrinterPack> packs);
}
