package cn.edu.zjut.dao;

import org.hibernate.query.Query;

public interface QueryFiller<T> {
    void fill(Query<T> queryObject);
}
