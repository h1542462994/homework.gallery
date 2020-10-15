package action;

import bean.UserBean;
import bean.UserRegisterBean;
import service.UserService;

public class UserAction {
    private UserRegisterBean loginUser;

    public UserRegisterBean getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(UserRegisterBean loginUser) {
        this.loginUser = loginUser;
    }

    public String login(){
        UserService userService = new UserService();
        if (userService.login(loginUser)){
            return "success";
        }
        return "fail";
    }

    public String register(){
        UserService userService = new UserService();
        if (userService.register(loginUser).isPass()){
            return "success";
        }
        return "fail";
    }
}
