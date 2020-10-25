package cn.edu.zjut.service;

import cn.edu.zjut.bean.UserBean;

public class UserService {
    public boolean login(UserBean user){
        if (user.getAccount().equals(user.getPassword())){
            return true;
        } else {
            return false;
        }
    }

    public boolean register(UserBean user){
        if (user.getAccount().isEmpty() || user.getPassword().isEmpty()) {
            return false;
        }

        if(!user.getAccount().equals(user.getPassword())) {
            return false;
        }

        if(!user.getPassword().equals(user.getRepassword())) {
            return false;
        }

        return true;
    }
}
