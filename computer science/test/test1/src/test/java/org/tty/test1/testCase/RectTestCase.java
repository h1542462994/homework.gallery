package org.tty.test1.testCase;

public class RectTestCase {
    private int length;
    private int width;
    private int result;
    private boolean error;

    public int getLength() {
        return length;
    }

    public void setLength(int length) {
        this.length = length;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getResult() {
        return result;
    }

    public void setResult(int result) {
        this.result = result;
    }

    public boolean isError() {
        return error;
    }

    public void setError(boolean error) {
        this.error = error;
    }

    public Object[] toObjects() {
        if (!this.error) {
            return new Object[] { length, width, result};
        } else {
            return new Object[] { length, width, "error"};
        }
    }
}
