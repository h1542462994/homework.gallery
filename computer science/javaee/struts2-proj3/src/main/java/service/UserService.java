package service;

import bean.*;
import validation.ActionResult;

public class UserService {
    public boolean login(UserBean user){
        if (user.getAccount().equals(user.getPassword())){
            return true;
        } else {
            return false;
        }
    }

    public ActionResult register(UserRegisterBean user) {
        if (user.getAccount().isEmpty() || user.getPassword().isEmpty()){
            return new ActionResult(false, 0, "用户名或者密码不能为空");
        }

        if (!user.getAccount().equals(user.getPassword())){
            return new ActionResult(false, 0, "用户名与密码不一致");
        }

        if (!user.getPassword().equals(user.getRepassword())){
            return new ActionResult(false, 0, "两次密码不一致");
        }

        return new ActionResult(true, 0, "登录成功");
    }
}
