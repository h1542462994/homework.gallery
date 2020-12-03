package cn.edu.zjut.dao.impl;

import cn.edu.zjut.dao.BaseHibernateDao;
import cn.edu.zjut.dao.ICustomerDao;
import cn.edu.zjut.po.Customer;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

public class CustomerDao extends BaseHibernateDao<Customer, Integer> implements ICustomerDao
{
    private final Log log = LogFactory.getLog(CustomerDao.class);
    public CustomerDao() {
        System.out.println("create CustomerDao");
    }

    @Override
    protected Log getLog() {
        return log;
    }

    @Override
    protected Class<Customer> getEntityClass() {
        return Customer.class;
    }

}
