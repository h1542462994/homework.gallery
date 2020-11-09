package cn.edu.zjut.dao;

import org.apache.commons.logging.Log;
import org.hibernate.Session;
import org.hibernate.query.Query;

import java.util.List;

@SuppressWarnings({"unchecked"})
public abstract class BaseHibernateDao<TEntity, TKey> {
    public final Session getSession(){
        return HibernateUtil.getSession();
    }

    protected abstract Log getLog();
    protected abstract Class<TEntity> getEntityClass();

    public List<TEntity> findByHql(String hql, Object... args) {
        getLog().debug("finding entity by hql");
        try {
            Query<TEntity> queryObject = (Query<TEntity>)getSession().createQuery(hql);
            for (int i = 0; i < args.length; ++i) {
                queryObject.setParameter(i, args[i]);
            }
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
