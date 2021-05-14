package org.tty.test3.dao;

import org.tty.test3.entity.User;

import java.util.HashMap;

public class InMemoryUserSet {
    HashMap<String, User> sets = new HashMap<>();

    public void addUser(User user) {
        sets.remove(user.getUsername());
        sets.put(user.getUsername(), user);
    }

    public boolean verifyUserName(String username) {
        return sets.keySet().stream().anyMatch(user -> user.equals(username));
    }

    public boolean verifyUserNameAndPassword(String username, String password) {
        return sets.values().stream().anyMatch(user ->
                user.getUsername().equals(username)
                        && user.getPassword().equals(password)
        );
    }
}
