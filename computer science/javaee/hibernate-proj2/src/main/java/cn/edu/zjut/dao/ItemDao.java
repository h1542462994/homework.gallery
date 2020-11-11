package cn.edu.zjut.dao;

import cn.edu.zjut.po.Item;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

public class ItemDao extends BaseHibernateDao<Item, String> {
    private final Log log = LogFactory.getLog(ItemDao.class);

    @Override
    protected Log getLog() {
        return log;
    }

    @Override
    protected Class<Item> getEntityClass() {
        return Item.class;
    }
}
