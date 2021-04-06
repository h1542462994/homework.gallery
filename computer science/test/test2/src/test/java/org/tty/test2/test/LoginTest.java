package org.tty.test2.test;


import org.junit.Test;
import org.junit.jupiter.api.Assertions;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.tty.test2.LoginServlet;
import org.tty.test2.foundation.MockFactory;
import org.tty.test2.foundation.ResultHook;
import org.tty.test2.foundation.TestCaseManager;
import org.tty.test2.testCase.LoginTestCase;

import javax.servlet.ServletException;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.HashMap;
import java.util.List;

@RunWith(Parameterized.class)
public class LoginTest {

    private final LoginTestCase loginTestCase;

    public LoginTest(LoginTestCase loginTestCase) {
        this.loginTestCase = loginTestCase;
    }

    /**
     * 读取测试用例数据
     */
    @Parameterized.Parameters(name = "{index}:{0}")
    public static List<LoginTestCase> data() throws FileNotFoundException {
        return TestCaseManager.getInstance().loadTestCase("LoginTest", LoginTestCase.class);
    }

    /**
     * 执行一次测试
     */
    @Test
    public void test() throws ServletException, IOException {
        // 读取测试用例的参数
        HashMap<String, String> params = loginTestCase.getParams();
        LoginServlet loginServlet = new LoginServlet();
        loginServlet.init(MockFactory.mockServletConfig());
        try {
            loginServlet.service(MockFactory.mockHttpServletRequest(params), MockFactory.mockHttpServletResponse());
        } catch (RuntimeException e) {
            // 在执行service时出现了错误
            ResultHook.getInstance().setValue("fail");
        } catch (Exception e) {
            ResultHook.getInstance().setValue("bug");
        }

        // 判断实际执行结果是否和预期输入一直。
        Assertions.assertEquals(loginTestCase.getResult(), ResultHook.getInstance().getValue());
    }
}
