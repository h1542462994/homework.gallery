package cn.edu.zjut.ejb;

import javax.ejb.Stateless;

@Stateless
public class UserService implements UserServiceRemote {
    public UserService() {}
    public boolean login(String username, String password) {
        return username.equals("zjut") && password.equals("zjut");
    }
}
