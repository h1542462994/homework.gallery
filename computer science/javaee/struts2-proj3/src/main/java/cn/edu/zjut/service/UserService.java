package cn.edu.zjut.service;

import cn.edu.zjut.bean.UserBean;
import cn.edu.zjut.exception.UserException;

public class UserService {
    public boolean login(UserBean user) throws Exception {
        if (user.getAccount().equalsIgnoreCase("admin")) {
            throw new UserException("用户名不能为admin");
        }
        if (user.getPassword().toUpperCase().contains(" AND ") ||
            user.getPassword().toUpperCase().contains(" OR ")) {
            throw new java.sql.SQLException("密码不能包括' and '或' or '");
        }

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
