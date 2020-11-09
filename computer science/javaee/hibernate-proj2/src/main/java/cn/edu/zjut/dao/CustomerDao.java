package cn.edu.zjut.dao;

import cn.edu.zjut.po.Customer;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import java.util.List;

public class CustomerDao extends BaseHibernateDao<Customer, Integer> {
    private final Log log = LogFactory.getLog(CustomerDao.class);

    @Override
    protected Log getLog() {
        return log;
    }

    @Override
    protected Class<Customer> getEntityClass() {
        return Customer.class;
    }

    public List<Customer> findByAccountAndPassword(String account, String password){
        return findByHql("from Customer as user where account=? and password=?", account, password);
    }

    public List<Customer> findByAccount(String account) {
        return findByHql("from Customer as user where account=?", account);
    }
}
