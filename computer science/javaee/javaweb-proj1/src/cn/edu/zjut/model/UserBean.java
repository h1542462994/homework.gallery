package com.edu.zjut.model;

public class UserBean {
    // 属性声明
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
