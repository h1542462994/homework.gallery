package cn.edu.zjut.dao.impl;

import cn.edu.zjut.dao.BaseHibernateDao;
import cn.edu.zjut.po.Customer;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

import java.util.List;

public class CustomerDao extends BaseHibernateDao<Customer, Integer> implements cn.edu.zjut.dao.CustomerDao {
    private final Log log = LogFactory.getLog(CustomerDao.class);

    @Override
    protected Log getLog() {
        return log;
    }

    @Override
    protected Class<Customer> getEntityClass() {
        return Customer.class;
    }

    @Override
    public void save(Customer transientInstance) {
        super.save(transientInstance);
    }
    @Override
    public void delete(Customer transientInstance) {
        super.delete(transientInstance);
    }
    @Override
    public void update(Customer transientInstance) {
        super.update(transientInstance);
    }
    @Override
    public <T> List<T> findByHql(String hql) {
        return super.findByHql(hql);
    }
}
