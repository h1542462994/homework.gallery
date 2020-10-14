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

    public ActionResult register() {

    }
}
