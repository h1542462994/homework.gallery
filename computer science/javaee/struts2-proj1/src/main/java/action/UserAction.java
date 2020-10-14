package action;

import bean.UserBean;
import service.UserService;

public class UserAction {
    private UserBean loginUser;

    public UserBean getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(UserBean loginUser) {
        this.loginUser = loginUser;
    }

    public String login(){
        UserService userService = new UserService();
        if (userService.login(loginUser)){
            return "success";
        }
        return "fail";
    }
}
