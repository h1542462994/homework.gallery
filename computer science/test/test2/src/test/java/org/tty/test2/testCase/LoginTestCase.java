package org.tty.test2.testCase;

import java.util.HashMap;

public class LoginTestCase {
    private HashMap<String, String> params;
    private String result;

    public HashMap<String, String> getParams() {
        return params;
    }

    public void setParams(HashMap<String, String> params) {
        this.params = params;
    }

    public String getResult() {
        return result;
    }

    public void setResult(String result) {
        this.result = result;
    }

    @Override
    public String toString() {
        return params + " " + result;
    }
}
