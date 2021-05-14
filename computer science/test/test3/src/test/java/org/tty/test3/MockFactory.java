package org.tty.test3;

import org.tty.test3.action.LoginAction;
import org.tty.test3.action.RegisterAction;
import org.tty.test3.dao.MockUserDao;
import org.tty.test3.service.UserService;

import java.util.Map;

public class MockFactory {
    public static UserService mockService() {
        UserService userService = new UserService();
        userService.setUserDao(MockUserDao.getProxy());
        return userService;
    }

    public static LoginAction mockLoginAction(Map<String, Object> session) {
        LoginAction loginAction = new LoginAction();
        loginAction.setUserService(mockService());
        loginAction.setSession(session);
        return loginAction;
    }

    public static RegisterAction mockRegisterAction() {
        RegisterAction registerAction = new RegisterAction();
        registerAction.setUserService(mockService());
        return registerAction;
    }
}
