package org.tty.test3;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.tty.test3.service.UserService;


public class UserServiceTest {
    private UserService userService;

    @BeforeEach
    public void initialize() {
        userService = MockFactory.mockService();
    }

    @Test
    public void test() {
        String password = "password";
        String username = "test1";
        Assertions.assertFalse(userService.loginVerify(username, password));
        userService.userRegister(username, password);
        Assertions.assertTrue(userService.loginVerify(username, password));
    }
}
