package org.tty.test1.test;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.tty.test1.Rect;
import org.tty.test1.foundation.TestCaseManager;
import org.tty.test1.testCase.RectTestCase;

import java.io.FileNotFoundException;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

@RunWith(Parameterized.class)
public class RectGetPerimeterTest {
    private final int length;
    private final int width;
    private final Object result;

    public RectGetPerimeterTest(int length, int width, Object result) {
        this.length = length;
        this.width = width;
        this.result = result;
    }

    @Parameterized.Parameters(name = "{index}: x={0},y={1},result={2}")
    public static List<Object[]> data() throws FileNotFoundException {
        TestCaseManager testCaseManager = TestCaseManager.getInstance();
        return testCaseManager.loadTestCaseAndMap("RectGetPerimeterTest", RectTestCase.class, RectTestCase::toObjects);
    }

    @Test
    public void test() {
        assertEquals(result, rectPerimeter(length, width));
    }

    private Object rectPerimeter(int length, int width) {
        try {
            Rect rect = new Rect(length, width);
            return rect.getPerimeter();
        } catch(Exception e) {
            e.printStackTrace();
            return "error";
        }
    }
}
