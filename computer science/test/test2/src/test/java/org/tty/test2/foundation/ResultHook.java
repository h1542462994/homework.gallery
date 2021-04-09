package org.tty.test2.foundation;

public class ResultHook {
    private static ResultHook gResultHook = null;
    private ResultHook() {}

    public Object getValue() {
        return value;
    }

    public void setValue(Object value) {
        this.value = value;
    }

    private Object value;

    public static ResultHook getInstance() {
        if (gResultHook == null){
            gResultHook = new ResultHook();
        }
        return gResultHook;
    }
}
