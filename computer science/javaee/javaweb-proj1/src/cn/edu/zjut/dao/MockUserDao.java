package cn.edu.zjut.dao;

import cn.edu.zjut.model.UserBean;

import java.util.HashSet;

public class MockUserDao implements UserDao {
    HashSet<UserBean> inMemoryUserBean = new HashSet<>();

    public MockUserDao(){
        UserBean userBean = new UserBean();
        userBean.setType(UserBean.ADMIN);
        userBean.setUsername("zjut");
        userBean.setPassword("zjut");
        inMemoryUserBean.add(userBean);
    }

    @Override
    public boolean searchUser(UserBean user) {
        if (inMemoryUserBean.contains(user)){
            return true;
        }

        return false;
    }

    @Override
    public boolean insertUser(UserBean user) {
        if (inMemoryUserBean.contains(user)){
            return false;
        } else {
            inMemoryUserBean.add(user);
            return true;
        }
    }


}
