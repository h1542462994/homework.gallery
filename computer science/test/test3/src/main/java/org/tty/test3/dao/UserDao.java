package org.tty.test3.dao;

import org.springframework.orm.hibernate3.HibernateTemplate;
import org.tty.test3.entity.User;

import java.util.List;

public class UserDao implements IUserDao {
    private HibernateTemplate hibernateTemplate;
    public void setHibernateTemplate(HibernateTemplate hibernateTemplate) {
        this.hibernateTemplate = hibernateTemplate;
    }

    // 添加用户
    @Override
    public boolean addUser(User user) {
        if(!verifyUsername(user.getUsername())) {
            hibernateTemplate.save(user);
            return true;
        }
        return false;
    }

    // 验证用户名是否存在
    @Override
    public boolean verifyUsername(String username) {
        List<User> users = (List<User>) hibernateTemplate.find("from User where username=?", username);
        return users.isEmpty() ? false:true;
    }

    // 验证密码是否正确
    @Override
    public boolean verifyPassword(String username, String password) {
        List queryList = hibernateTemplate.find("select password from User where username=?", username);

        return ( queryList.get(0).toString() ).equals(password);
    }
}
