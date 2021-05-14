package org.tty.psellor.printer;

public interface Printer {
    Double prize();
    default String brand() {
        return PrinterRegistry.brand(this.getClass());
    }

}
