package cn.edu.zjut.dao;

import cn.edu.zjut.po.Item;
import cn.edu.zjut.po.ItemBasic;
import cn.edu.zjut.po.ItemDetail;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.hibernate.Session;
import org.hibernate.query.Query;

import java.io.Serializable;
import java.util.List;

@SuppressWarnings({"unchecked"})
public class ItemDao implements Serializable {
    private static final Log log = LogFactory.getLog(ItemDao.class);

    public List<Item> findAll() throws RuntimeException {
        log.debug("finding all Item instances");
//        SessionFactory sessionFactory = new Configuration()
//                .configure().buildSessionFactory();
//        try (Session session = sessionFactory.openSession()) {
//            String queryString = "from Item";
//            Query<Item> queryObject = (Query<Item>) session.createQuery(queryString);
//            return queryObject.list();
//        } catch (RuntimeException e) {
//            log.error("find all failed", e);
//            throw e;
//        }
        Session session = SessionUtil.getSession();
        String queryString = "from Item";
        Query<Item> queryObject = (Query<Item>) session.createQuery(queryString);
        return queryObject.list();
    }

    public List<ItemBasic> findAllBasic() throws RuntimeException {
        log.debug("finding all ItemBasic instances");
        Session session = SessionUtil.getSession();
        String queryString = "from ItemBasic";
        Query<ItemBasic> queryObject = (Query<ItemBasic>) session.createQuery(queryString);
        return queryObject.list();
    }

    public List<ItemDetail> findAllDetail() throws RuntimeException {
        log.debug("finding all ItemDetail instances");
        Session session = SessionUtil.getSession();
        String queryString = "from ItemDetail";
        Query<ItemDetail> queryObject = (Query<ItemDetail>) session.createQuery(queryString);
        return queryObject.list();
    }
}
