package cn.edu.zjut.dao;

import org.hibernate.query.Query;

public interface QueryFiller<TEntity> {
    void fill(Query<TEntity> queryObject);
}
