package org.tty.psellor.printer;

import org.tty.psellor.printer.sells.NoPrinterSells;
import org.tty.psellor.printer.sells.PrinterSells;

import java.util.ArrayList;
import java.util.Iterator;

public class PrinterCollection implements Iterable<PrinterPack> {
    public PrinterCollection() {
        setPrinterSells(new NoPrinterSells());
    }

    private final ArrayList<PrinterPack> printerPacks = new ArrayList<>();
    private PrinterSells printerSells;

    public PrinterCollection addPrint(String vendor, String version) {
        return addPrints(vendor, version, 1);
    }

    public PrinterCollection addPrints(String vendor, String version, Integer count) {
        try {
            Class<? extends Printer> printClazz = PrinterRegistry.getInstance().get(vendor, version);
            Printer printer = printClazz.newInstance();
            printerPacks.add(new PrinterPack(printer, count));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return this;
    }

    public PrinterCollection addPrint(Class<? extends Printer> printClazz) {
        return addPrints(printClazz, 1);
    }

    public PrinterCollection addPrints(Class<? extends Printer> printClazz, Integer count) {
        try {
            Printer printer = printClazz.newInstance();
            printerPacks.add(new PrinterPack(printer, count));
        } catch (Exception e) {
            e.printStackTrace();
        }
        return this;
    }


    @Override
    public Iterator<PrinterPack> iterator() {
        return printerPacks.iterator();
    }

    public Double totalPrize() {
        return printerSells.totalPrize(this);
    }

    public PrinterSells getPrinterSells() {
        return printerSells;
    }

    public void setPrinterSells(PrinterSells printerSells) {
        this.printerSells = printerSells;
    }
}
