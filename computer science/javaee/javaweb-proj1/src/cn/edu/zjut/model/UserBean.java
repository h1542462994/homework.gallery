package cn.edu.zjut.model;

import java.util.Objects;

public class UserBean {
    public static final int ADMIN = 1;
    public static final int NORMAL = 2;

    public int getType() {
        return type;
    }

    public void setType(int type) {
        this.type = type;
    }

    // 属性声明
    private int type;
    private String username;
    private String password;
    // 构造方法
    public UserBean() {}

    // getter
    public String getUsername() {
        return username;
    }

    // setter
    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    // add comparable interface to hashset<E>.
    @Override
    public int hashCode() {
        return Objects.hash(type, username, password);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null)
            return false;
        if (!(obj instanceof UserBean))
            return false;
        UserBean instance = (UserBean)obj;
        return type == instance.type &&
                username.equals(instance.username) &&
                password.equals(instance.password);
    }

    public static boolean validate(UserBean user) {
        if (!(user.type == UserBean.ADMIN || user.type == UserBean.NORMAL)) {
            return false;
        }
        if (user.username == null || user.username.isEmpty() || user.username.length() > 6) {
            return false;
        }
        if (user.password == null || user.password.isEmpty() || user.password.length() > 6) {
            return false;
        }
        return true;
    }
}
