package cn.edu.zjut.dao;

import cn.edu.zjut.po.Customer;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import java.util.List;

public class CustomerDao extends BaseHibernateDao<Customer, Integer> {
    private final Log log = LogFactory.getLog(CustomerDao.class);

    @Override
    protected Log getLog() {
        return this.log;
    }

    @Override
    protected Class<Customer> getEntityClass() {
        return Customer.class;
    }

    public Customer findByAccount(String account) {
        List<Customer> list = findByHql("from Customer where account = :account", query -> {
            query.setParameter("account", account);
        });
        if (list.isEmpty()) {
            return null;
        } else {
            return list.get(0);
        }
    }
}
