package cn.edu.zjut.action;

import cn.edu.zjut.bean.UserBean;
import cn.edu.zjut.service.UserService;
import com.opensymphony.xwork2.*;
import com.sun.jmx.snmp.SnmpUnknownAccContrModelException;

public class UserAction extends ActionSupport {
    private static final String FAIL = "fail";
    private UserBean loginUser;

    public UserBean getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(UserBean loginUser) {
        this.loginUser = loginUser;
    }

    public String login(){
        UserService userService = new UserService();
        if (userService.login(loginUser)) {
            return SUCCESS;
        }

        return FAIL;
    }

    public String register(){
        UserService userService = new UserService();
        if (userService.register(loginUser)) {
            return SUCCESS;
        }

        return FAIL;
    }
}
