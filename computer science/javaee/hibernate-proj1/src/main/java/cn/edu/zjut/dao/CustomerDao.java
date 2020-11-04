package cn.edu.zjut.dao;

import org.apache.commons.logging.*;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.hibernate.query.Query;

import java.util.List;

@SuppressWarnings({"unchecked"})
public class CustomerDao {
    private final Log log = LogFactory.getLog(CustomerDao.class);

    public <T> List<T> findByHql(String hql) throws RuntimeException {
        log.debug("finding LoginUser instance by hql");
        SessionFactory sessionFactory = new Configuration().configure().buildSessionFactory();
        try (Session session = sessionFactory.openSession()) {
            Query<T> queryObject = (Query<T>) session.createQuery(hql);
            return queryObject.list();
        } catch (RuntimeException e) {
            log.error("find by hql failed", e);
            throw e;
        }
    }
}
