package org.tty.psellor;

import org.tty.psellor.printer.Hp5213Printer;
import org.tty.psellor.printer.PrinterCollection;
import org.tty.psellor.printer.PrinterRegistry;
import org.tty.psellor.printer.sells.DiffPrinterSells;
import org.tty.psellor.printer.sells.NoPrinterSells;

public class Main {
    public static void main(String[] args) {
        // 注册
        PrinterRegistry registry = PrinterRegistry.getInstance();
        registry.register(Hp5213Printer.class);


        PrinterCollection collection = new PrinterCollection();
        // 设置折扣方式
        collection.setPrinterSells(new NoPrinterSells());
        collection.
                addPrints("hp", "5213", 5);


        System.out.println("不打折:" + collection.totalPrize());

        collection.setPrinterSells(new DiffPrinterSells(100.0));
        System.out.println("每件减100:" + collection.totalPrize());
    }
}
