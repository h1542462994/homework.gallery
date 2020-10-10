package cn.edu.zjut.model;

public class UserBean {
    public static final int ADMIN = 1;
    public static final int NORMAL = 0;

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
}
