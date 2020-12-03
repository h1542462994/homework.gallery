package cn.edu.zjut.action;

import cn.edu.zjut.po.Customer;
import cn.edu.zjut.service.IUserService;
import com.opensymphony.xwork2.ActionSupport;

public class UserAction extends ActionSupport {
    private Customer loginUser;
    private IUserService userService = null;

    public Customer getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(Customer loginUser) {
        this.loginUser = loginUser;
    }

    public void setUserService(IUserService userService) {
        this.userService = userService;
    }

    public String register(){
        userService.register(loginUser);
        return SUCCESS;
    }
}
