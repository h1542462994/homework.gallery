package cn.edu.zjut.dao;

import cn.edu.zjut.model.UserBean;

public interface UserDao {
    /**
     * to search where user exists.
     */
    boolean searchUser(UserBean user);

    /**
     * to insert a user in set.
     * @return false means the insert operation failed.
     */
    boolean insertUser(UserBean user);
}
