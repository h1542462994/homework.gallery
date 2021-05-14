package org.tty.test3;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.tty.test3.action.LoginAction;
import org.tty.test3.entity.User;
import org.tty.test3.service.UserService;

import java.util.HashMap;
import java.util.Map;

public class LoginActionTest {
    Map<String, Object> session;
    LoginAction loginAction;
    UserService userService;

    @BeforeEach
    public void initialize() {
        session = new HashMap<>();
        userService = MockFactory.mockService();
        loginAction = new LoginAction();
        loginAction.setSession(session);
        loginAction.setUserService(userService);

        // 先存入一个用户
        userService.userRegister("test", "123456");
    }

    @Test
    public void testOk() {
        String username = "test";
        String password = "123456";

        loginAction.setUsername(username);
        loginAction.setPassword(password);

        String result = loginAction.execute();
        User user = (User) session.get("user");
        Assertions.assertEquals(username, user.getUsername());
        Assertions.assertEquals(password, user.getPassword());
        Assertions.assertEquals("success", result);
    }

    @Test
    public void testFail() {
        String username = "test";
        String password = "12345";

        loginAction.setUsername(username);
        loginAction.setPassword(password);

        String result = loginAction.execute();
        Assertions.assertEquals("input", result);
        Assertions.assertTrue(loginAction.getActionErrors().stream().anyMatch((msg) -> msg.equals("账号或密码错误！")));
    }
}
