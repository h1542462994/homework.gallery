package org.tty.test1.test;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.tty.test1.Rect;
import org.tty.test1.foundation.TestCaseManager;
import org.tty.test1.testCase.FindMaxTestCase;

import java.io.FileNotFoundException;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

@RunWith(Parameterized.class)
public class RectFindMaxTest {
    private FindMaxTestCase testCase;

    public RectFindMaxTest(FindMaxTestCase except) {
        this.testCase = except;
    }

    @Parameterized.Parameters(name = "{index}: x={0}")
    public static List<FindMaxTestCase> data() throws FileNotFoundException {
        TestCaseManager testCaseManager = TestCaseManager.getInstance();
        return testCaseManager.loadTestCase("RectFindMaxTest", FindMaxTestCase.class);
    }

    @Test
    public void testArea() {
        FindMaxTestCase result = findMax(testCase);
        assertEquals(testCase.isError(), result.isError());
        if (!result.isError()) {
            assertEquals(testCase.getResultArea().getObject(), result.getResultArea().getObject());
        }
    }

    @Test
    public void testPerimeter() {
        FindMaxTestCase result = findMax(testCase);
        assertEquals(testCase.isError(), result.isError());
        if (!result.isError()) {
            assertEquals(testCase.getResultArea().getObject(), result.getResultArea().getObject());
        }
    }

    private FindMaxTestCase findMax(FindMaxTestCase except) {
        try {
            Rect resultArea = Rect.findMax(except.getInput(), new Rect.areaCompare());
            Rect resultPerimeter = Rect.findMax(except.getInput(), new Rect.perimeterCompare());
            return except.toResult(false, resultArea, resultPerimeter);
        } catch (Exception e) {
            e.printStackTrace();
            return except.toResult(true, null, null);
        }
    }
}
