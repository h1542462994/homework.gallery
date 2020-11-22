package cn.edu.zjut.action;

import cn.edu.zjut.po.Address;
import cn.edu.zjut.po.Customer;
import cn.edu.zjut.service.UserService;
import com.opensymphony.xwork2.ActionContext;
import com.opensymphony.xwork2.ActionSupport;

public class UserAction extends ActionSupport {
    public UserAction(){
        super();
        userService = new UserService(ActionContext.getContext());
    }

    private final UserService userService;
    private static final String FAIL = "fail";
    private Customer loginUser;
    private Address address;

    public Customer getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(Customer loginUser) {
        this.loginUser = loginUser;
    }

    public Address getAddress() {
        return address;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    public String login() {
        if (userService.login(loginUser)) {
            return SUCCESS;
        } else {
            return FAIL;
        }
    }

    public String addAddr() {
        if (userService.addAddress(loginUser, address)) {
            return SUCCESS;
        } else {
            return FAIL;
        }
    }
}
