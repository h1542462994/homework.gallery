package org.tty.test3.dao;

import org.tty.test3.entity.User;

public interface IUserDao {
    // 添加用户
    boolean addUser(User user);

    // 验证用户名是否存在
    boolean verifyUsername(String username);

    // 验证密码是否正确
    boolean verifyPassword(String username, String password);
}
