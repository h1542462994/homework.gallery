package cn.edu.zjut.dao;

import org.apache.commons.logging.Log;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.query.Query;

import java.util.List;

public abstract class BaseHibernateDao<TEntity, TKey> {
    private SessionFactory sessionFactory;
    private final ThreadLocal<Session> session = new ThreadLocal<>();
    protected abstract Log getLog();
    protected abstract Class<TEntity> getEntityClass();

    public Session getSession(){
        if (session.get() == null || !session.get().isOpen()){
            session.set(sessionFactory.openSession());
        }
        return session.get();
    }

    public void setSessionFactory(SessionFactory sessionFactory) {
        this.sessionFactory = sessionFactory;
    }

    public <T> List<T> findByHql(String hql){
        return findByHql(hql, (query) -> {});
    }

    @SuppressWarnings("unchecked")
    public <T> List<T> findByHql(String hql, QueryFiller<T> filler){
        getLog().debug("finding entity by hql");
        try {
            Query<T> queryObject = (Query<T>)getSession().createQuery(hql);
            filler.fill(queryObject);
            return queryObject.list();
        } catch (RuntimeException e) {
            getLog().debug("find entity by hql failed", e);
            throw e;
        }
    }

    public void save(TEntity entity) {
        getLog().debug("saving entity");
        try {
            getSession().save(entity);
            getLog().debug("save entity successful");
        } catch (RuntimeException e) {
            getLog().error("save failed", e);
            throw e;
        }
    }

    public void update(TEntity entity) {
        getLog().debug("update entity");
        try {
            getSession().update(entity);
            getLog().debug("update entity successful");
        } catch (RuntimeException e) {
            getLog().error("update failed", e);
            throw e;
        }
    }

    public void delete(TEntity entity){
        getLog().debug("delete entity");
        try {
            getSession().delete(entity);
            getLog().debug("delete entity successful");
        } catch (RuntimeException e) {
            getLog().error("delete failed", e);
            throw e;
        }
    }

    public TEntity find(TKey key) {
        getLog().debug("find entity by key");
        TEntity entity;
        try {
            entity = getSession().find(getEntityClass(), key);
            getLog().debug("find entity by key successful");
        } catch (RuntimeException e) {
            getLog().error("find entity by key failed", e);
            throw e;
        }
        return entity;
    }
}
