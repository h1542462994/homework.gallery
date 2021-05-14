package org.tty.test3.service;


import org.springframework.transaction.annotation.Transactional;
import org.tty.test3.dao.IUserDao;
import org.tty.test3.entity.User;


@Transactional
public class UserService {
    private IUserDao IUserDao;
    public void setUserDao(IUserDao IUserDao) {
        this.IUserDao = IUserDao;
    }

    public boolean loginVerify(String username, String password) {
        boolean passLogin = false;
        passLogin = IUserDao.verifyUsername(username);
        if(passLogin) {
            passLogin = IUserDao.verifyPassword(username, password);
        }
        return passLogin;
    }

    public boolean userRegister(String username, String password) {
        User user = new User();
        user.setUsername(username);
        user.setPassword(password);
        return IUserDao.addUser(user);
    }
}
