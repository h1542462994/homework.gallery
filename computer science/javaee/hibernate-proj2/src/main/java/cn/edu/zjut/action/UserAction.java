package cn.edu.zjut.action;

import cn.edu.zjut.po.Customer;
import cn.edu.zjut.service.UserService;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

public class UserAction extends ActionSupport {
    private Customer loginUser;
    private static final String FAIL = "fail";

    public Customer getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(Customer loginUser) {
        this.loginUser = loginUser;
    }

    public static ActionContext getActionContext() {
        return ActionContext.getContext();
    }

    public String login() {
        UserService userService = new UserService(getActionContext());
        if (userService.login(loginUser)) {
            return SUCCESS;
        } else {
            return FAIL;
        }
    }

    public String register() {
        UserService userService = new UserService(getActionContext());
        if (userService.register(loginUser)) {
            return SUCCESS;
        } else {
            return FAIL;
        }
    }

    public String update() {
        UserService userService = new UserService(getActionContext());
        if (userService.update(loginUser)) {
            return SUCCESS;
        } else {
            return FAIL;
        }
    }

    public String delete() {
        UserService userService = new UserService(getActionContext());
        if (userService.delete(loginUser)) {
            return SUCCESS;
        } else {
            return FAIL;
        }
    }
}
