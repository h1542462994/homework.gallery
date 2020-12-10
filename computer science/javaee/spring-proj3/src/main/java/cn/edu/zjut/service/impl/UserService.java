package cn.edu.zjut.service.impl;

import cn.edu.zjut.dao.CustomerDao;
import cn.edu.zjut.po.Customer;

public class UserService implements cn.edu.zjut.service.UserService {
    private CustomerDao customerDao = null;
    public void setCustomerDao(CustomerDao customerDao) {
        System.out.println("call setCustomerDao in UserService.");
        this.customerDao = customerDao;
    }

    @Override
    public void addUser(Customer customer) {
        System.out.println("execute --addUser()-- method.");
        customerDao.save(customer);
    }

    @Override
    public void delUser(Customer customer) {
        System.out.println("execute --delUser()-- method.");
        customerDao.delete(customer);
    }

    @Override
    public void updateUser(Customer customer) {
        System.out.println("execute --updateUser()-- method.");
        customerDao.update(customer);
    }

    @Override
    public Customer findUser(Customer customer) {
        System.out.println("execute --findUser()-- method.");
        customerDao.findByHql("from Customer where customer.Id = :customerId");
        return null;
    }
}
