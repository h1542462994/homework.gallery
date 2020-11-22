package cn.edu.zjut.dao;

import cn.edu.zjut.po.Address;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

public class AddressDao extends BaseHibernateDao<Address, Integer> {
    private final Log log = LogFactory.getLog(AddressDao.class);

    @Override
    protected Log getLog() {
        return this.log;
    }

    @Override
    protected Class<Address> getEntityClass() {
        return Address.class;
    }
}
