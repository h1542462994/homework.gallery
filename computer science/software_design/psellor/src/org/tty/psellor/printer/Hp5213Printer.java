package org.tty.psellor.printer;

@PrintBrand(vendor = "hp", version = "5213")
public class Hp5213Printer implements Printer {
    @Override
    public Double prize() {
        return 5200.0;
    }
}

