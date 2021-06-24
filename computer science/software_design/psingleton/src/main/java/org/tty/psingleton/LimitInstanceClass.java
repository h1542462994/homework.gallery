package org.tty.psingleton;

import java.util.Optional;
import java.util.Properties;
import java.util.concurrent.ConcurrentHashMap;

public class LimitInstanceClass {
    //region object field and functions
    private Integer id = 0;

    private Boolean isBusy = false;

    private String accessMessage = "";

    public Integer getId() {
        return id;
    }

    public Boolean getBusy() {
        return isBusy;
    }

    public void release() {
        isBusy = false;
    }

    public void writeAccessMessage(String message) {
        accessMessage = message;
    }

    public void printAccessMessage() {
        System.out.println(accessMessage + "," + this.id);
    }

    //endregion


    //region static field and functions
    private static Integer instanceLimit = 0;
    private volatile static Integer generateId = 1;
    private static final ConcurrentHashMap<Integer, LimitInstanceClass> instances = new ConcurrentHashMap<>();

    public static void prepare( Properties properties) {
        instanceLimit = Integer.parseInt(properties.getProperty("instanceLimit"));
    }

    public static Integer getInstanceLimit() {
        return instanceLimit;
    }

    private static boolean available() {
        if (instances.size() < instanceLimit) {
            return true;
        } else {
            return instances.values().stream().anyMatch(t -> !t.isBusy);
        }
    }

    private static Optional<LimitInstanceClass> first() {
        return instances.values().stream().filter(t -> !t.isBusy).findAny();
    }

    private static LimitInstanceClass newInstance() {
        var instance = new LimitInstanceClass();
        instance.id = generateId;
        generateId = instance.id + 1;
        instance.isBusy = true;
        instances.put(instance.id, instance);
        return instance;
    }

    public static LimitInstanceClass getInstance() {
        if (available()) {
            synchronized (LimitInstanceClass.class) {
                if (available()) {
                   var ls = first();
                   if (ls.isPresent()) {
                       var instance = ls.get();
                       instance.isBusy = true;
                       return instance;
                   } else {
                       return newInstance();
                   }
                }
            }
        }

        return null;
    }
    //endregion
}
