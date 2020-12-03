package cn.edu.zjut.service.impl;

import cn.edu.zjut.dao.ICustomerDao;
import cn.edu.zjut.po.Customer;
import cn.edu.zjut.service.IUserService;
import org.hibernate.Session;
import org.hibernate.Transaction;

public class UserService implements IUserService {
    private ICustomerDao customerDao = null;

    public UserService() {
        System.out.println("create UserService");
    }




    public void setCustomerDao(ICustomerDao customerDao) {
        System.out.println("--setCustomerDao--");
        this.customerDao = customerDao;
    }

    @Override
    public void register(Customer customer) {
        Transaction transaction = null;
        try (Session session = customerDao.getSession()) {
            transaction = session.beginTransaction();
            customerDao.save(customer);
            transaction.commit();
        } catch (RuntimeException e) {
            if (transaction != null) transaction.rollback();
            throw e;
        }
    }
}
