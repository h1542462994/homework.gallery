package cn.edu.zjut.dao;

import cn.edu.zjut.po.Customer;
import org.hibernate.Session;

public interface ICustomerDao {
    Session getSession();
    void save(Customer customer);
}
