package cn.edu.zjut.dao;

import cn.edu.zjut.po.Customer;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.hibernate.Session;
import org.hibernate.query.Query;

import java.io.Serializable;
import java.util.List;

@SuppressWarnings({"unchecked"})
public class CustomerDao implements Serializable {
    private final Log log = LogFactory.getLog(CustomerDao.class);

    public <T> List<T> findByHql(String hql) throws RuntimeException {
        log.debug("finding LoginUser instance by hql");
//        SessionFactory sessionFactory = new Configuration().configure().buildSessionFactory();
//        try (Session session = sessionFactory.openSession()) {
//            Query<T> queryObject = (Query<T>) session.createQuery(hql);
//            return queryObject.list();
//        } catch (RuntimeException e) {
//            log.error("find by hql failed", e);
//            throw e;
//        }

        Session session = SessionUtil.getSession();
        Query<T> queryObject = (Query<T>) session.createQuery(hql);
        return queryObject.list();
    }

    public void save(Customer customer) throws RuntimeException {
        log.debug("saving customer instance");
//        SessionFactory sessionFactory = new Configuration()
//                .configure().buildSessionFactory();
//        try (Session session = sessionFactory.openSession()) {
//            session.save(customer);
//            //session.flush();
//            log.debug("save successful");
//        } catch (RuntimeException e) {
//            log.error("save failed", e);
//            throw e;
//        }

        Session session = SessionUtil.getSession();
        session.save(customer);
    }
}
