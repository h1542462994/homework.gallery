package cn.edu.zjut.dao;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;


public class SessionUtil {
    private static Session session;

    public static Session getSession(){
        if (session == null) {
            SessionFactory sessionFactory = new Configuration()
                    .configure().buildSessionFactory();
            session = sessionFactory.openSession();
        }
        return session;
    }
}
