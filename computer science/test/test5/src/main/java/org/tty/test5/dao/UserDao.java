package org.tty.test5.dao;

import org.hibernate.Session;
import org.tty.test5.model.User;

import java.util.List;

public class UserDao extends SessionUtil {
    public List<User> findByUsernameAndPassword(String username, String password) {
        return SessionUtil.query(
                "from User as user where username = '" + username + "' and password = '" + password + "'"
        );
    }

    public List<User> findByUserName(String username) {
        return SessionUtil.query(
                "from User as user where username = '" + username + "'"
        );
    }

    public void save(User user) {
        SessionUtil.save(user);
    }
}
