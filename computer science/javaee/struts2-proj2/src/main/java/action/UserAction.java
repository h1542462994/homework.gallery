package action;

import bean.UserBean;
import bean.UserRegisterBean;
import com.opensymphony.xwork2.ActionSupport;
import service.UserService;

public class UserAction extends ActionSupport {
    private UserRegisterBean loginUser;

    public UserRegisterBean getLoginUser() {
        return loginUser;
    }

    public void setLoginUser(UserRegisterBean loginUser) {
        this.loginUser = loginUser;
    }

    public String login() {
        UserService userService = new UserService();
        if (userService.login(loginUser)) {
            this.addActionMessage(getText("login.action.success"));
            return "success";
        }
        this.addActionError(getText("login.action.fail"));
        return "fail";
    }

    public String register() {
        UserService userService = new UserService();
        if (userService.register(loginUser).isPass()) {
            return "success";
        }
        return "fail";
    }

//    public void validateLogin() {
//        String account = loginUser.getAccount();
//        String password = loginUser.getPassword();
//        if (account == null || account.equals("")) {
//            this.addFieldError("loginUser.account", getText("login.account.error"));
//        }
//        if (password == null || password.equals("")) {
//            this.addFieldError("loginUser.password", getText("login.password.error"));
//        }
//    }

    public void validateRegister(){

        //begins.. account
        String account = loginUser.getAccount();
        if (account == null || account.equals("")) {
            this.addFieldError("loginUser.account", getText("login.account.error"));
            
        }
    }
}
