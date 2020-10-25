package cn.edu.zjut.action;

import cn.edu.zjut.bean.*;
import cn.edu.zjut.service.*;
import com.opensymphony.xwork2.*;
import java.util.*;

public class UserAction extends ActionSupport {
    private static final String FAIL = "fail";
    private static final String USER = "user";
    private UserBean loginUser;

    private Map<String, Object> session;

    public UserBean getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(UserBean loginUser) {
        this.loginUser = loginUser;
    }

    public String login(){
        ActionContext actionContext = ActionContext.getContext();
        session = actionContext.getSession();
        UserService userService = new UserService();
        if (userService.login(loginUser)) {
            session.put(USER, loginUser.getAccount());
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
