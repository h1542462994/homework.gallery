package org.tty.psellor.printer;

import java.util.HashMap;
import java.util.Map;

public class PrinterRegistry {
    private final Map<String, Class<? extends Printer>> brands = new HashMap<>();

    private static volatile PrinterRegistry instance = null;
    public static PrinterRegistry getInstance() {
        if (instance == null) {
            instance = new PrinterRegistry();
        }
        return instance;
    }

    public static String brand(Class<? extends Printer> type) {
        PrintBrand brand = type.getAnnotation(PrintBrand.class);
        return brand.vendor() + "," + brand.version();
    }

    public static String brand(String vendor, String version) {
        return vendor + "," + version;
    }

    public void register(Class<? extends Printer> type) {
        brands.put(brand(type), type);
    }

    public Class<? extends Printer> get(String brand, String version){
        return brands.get(brand(brand, version));
    }

}
