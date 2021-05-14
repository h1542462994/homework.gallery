package org.tty.test5.dao;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;
import org.hibernate.query.Query;

import java.util.List;

public class SessionUtil {
    private static Session session;

    public static Session getSession() {
        if (session == null) {
            SessionFactory sessionFactory = new Configuration().configure().buildSessionFactory();
            session = sessionFactory.openSession();
        }
        return session;
    }

    @SuppressWarnings({"unchecked"})
    public static <T> List<T> query(String hql) throws RuntimeException {
        Session session = getSession();
        Query<T> queryObject = (Query<T>) session.createQuery(hql);
        return queryObject.list();
    }

    public static <T> void save(T instance) throws RuntimeException {
        Session session = getSession();
        session.save(instance);
    }
}
