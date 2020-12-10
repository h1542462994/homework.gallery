package cn.edu.zjut.service;

import cn.edu.zjut.po.Customer;

public interface UserService {
    void addUser(Customer customer);

    void delUser(Customer customer);

    void updateUser(Customer customer);

    Customer findUser(Customer customer);
}
