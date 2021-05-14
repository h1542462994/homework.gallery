package org.tty.test3;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.tty.test3.action.RegisterAction;

public class RegisterActionTest {
    private RegisterAction registerAction;

    @BeforeEach
    public void initialize() {
        registerAction = MockFactory.mockRegisterAction();
    }

    /**
     * 测试用户名为空的情况
     */
    @Test()
    public void testUserNameEmpty() {
        String username = "";
        String password = "123456";
        registerAction.setUsername(username);
        registerAction.setPassword(password);
        registerAction.validate();
        Assertions.assertTrue(registerAction.getActionErrors().stream().anyMatch((msg) -> msg.equals("用户名不能为空！")));
    }

    /**
     * 测试密码为空的情况
     */
    @Test
    public void testPasswordEmpty() {
        String username = "test1";
        String password = "";
        registerAction.setUsername(username);
        registerAction.setPassword(password);
        registerAction.validate();
        Assertions.assertTrue(registerAction.getActionErrors().stream().anyMatch((msg) -> msg.equals("密码不能为空！")));
    }

    /**
     * 测试注册
     */
    @Test
    public void testRegister() {
        String username = "test1";
        String password = "123456";
        registerAction.setUsername(username);
        registerAction.setPassword(password);
        registerAction.validate();
        registerAction.execute();
        // 没有错误
        Assertions.assertFalse(registerAction.hasActionErrors());
        // 有对应的提示消息
        Assertions.assertTrue(registerAction.getActionMessages().stream().anyMatch((msg) -> msg.equals("注册成功！")));
    }

    /**
     * 测试用户重复的情况
     */
    @Test
    public void testRegisterRedundant() {

        String username = "test1";
        String password = "123456";
        registerAction.setUsername(username);
        registerAction.setPassword(password);
        registerAction.validate();
        registerAction.execute();
        registerAction.validate();
        registerAction.execute();

        Assertions.assertTrue(registerAction.getActionErrors().stream().anyMatch((msg) -> msg.equals("注册失败,该用户名已存在！")));
    }
}
