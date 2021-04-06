package org.tty.test1.testCase;

import org.tty.test1.Rect;

import java.util.Arrays;
import java.util.Objects;

public class FindMaxTestCase {
    private Rect[] input;
    private boolean error;
    private Rect resultArea;
    private Rect resultPerimeter;

    public Rect[] getInput() {
        return input;
    }

    public void setInput(Rect[] input) {
        this.input = input;
    }

    public boolean isError() {
        return error;
    }

    public void setError(boolean error) {
        this.error = error;
    }

    public Rect getResultArea() {
        return resultArea;
    }

    public void setResultArea(Rect resultArea) {
        this.resultArea = resultArea;
    }

    public Rect getResultPerimeter() {
        return resultPerimeter;
    }

    public void setResultPerimeter(Rect resultPerimeter) {
        this.resultPerimeter = resultPerimeter;
    }

    public Object[] toObjects() {
        return new Object[] { input, error, resultArea, resultPerimeter };
    }

    public FindMaxTestCase toResult(boolean error, Rect resultArea, Rect resultPerimeter) {
        FindMaxTestCase findMaxTestCase = new FindMaxTestCase();
        findMaxTestCase.input = this.input;
        findMaxTestCase.error = error;
        findMaxTestCase.resultArea = resultArea;
        findMaxTestCase.resultPerimeter = resultPerimeter;
        return findMaxTestCase;
    }


    @Override
    public String toString() {
        return "FindMaxTestCase{" +
                "input=" + Arrays.toString(input) +
                ", error=" + error +
                ", resultArea=" + resultArea +
                ", resultPerimeter=" + resultPerimeter +
                '}';
    }
}
