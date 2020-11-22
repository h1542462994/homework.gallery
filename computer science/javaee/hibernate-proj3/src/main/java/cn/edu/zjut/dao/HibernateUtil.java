package cn.edu.zjut.dao;

import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

public class HibernateUtil {
    private static final String CONFIG_FILE_LOCATION="/hibernate.cfg.xml";
    // use thread combination visitor
    private static final ThreadLocal<Session> threadLocal = new ThreadLocal<>();
    private static final Configuration configuration = new Configuration();
    private static SessionFactory sessionFactory;

    private static String configFile = CONFIG_FILE_LOCATION;

    // static initializer is unsafe, please rewrite with injection.
    // because we can't determine when it will be called.
//    static {
//        rebuildSessionFactory();
//    }

    private HibernateUtil() {} // to avoid dynamic constructor

    public static SessionFactory getSessionFactory() {
        return sessionFactory;
    }

    public static void rebuildSessionFactory(){
        try {
            configuration.configure(configFile);
            sessionFactory = configuration.buildSessionFactory();
        } catch (Exception e) {
            // please logging by loggingFactory
            System.err.println("%%%%Error Creating SessionFactory%%%%");
            e.printStackTrace();
        }
    }

    public static String getConfigFile() {
        return configFile;
    }

    public static void setConfigFile(String configFile) {
        HibernateUtil.configFile = configFile;
        sessionFactory = null;
        //rebuildSessionFactory();
    }

    public static Configuration getConfiguration() {
        return configuration;
    }

    public static Session getSession(){
        Session session = threadLocal.get();
        if (session == null || !session.isOpen()) {
            if (sessionFactory == null) {
                rebuildSessionFactory();
            }
            session = sessionFactory.openSession();
            threadLocal.set(session);
        }
        return session;
    }

    public static void closeSession() throws HibernateException {
        Session session = threadLocal.get();
        threadLocal.set(null);
        if (session != null) {
            session.close();
        }
    }
}
