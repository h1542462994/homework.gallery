package org.tty.psellor.printer;

public class PrinterPack {
    public PrinterPack(Printer printer, Integer count) {
        this.printer = printer;
        this.count = count;
    }

    Printer printer;
    Integer count;

    public Printer getPrinter() {
        return printer;
    }

    public void setPrinter(Printer printer) {
        this.printer = printer;
    }

    public Integer getCount() {
        return count;
    }

    public void setCount(Integer count) {
        this.count = count;
    }
}
