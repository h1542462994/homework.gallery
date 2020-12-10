package cn.edu.zjut.dao;

import cn.edu.zjut.po.Customer;

import java.util.List;

public interface CustomerDao {
    void save(Customer transientInstance);

    void delete(Customer transientInstance);

    void update(Customer transientInstance);

    <T> List<T> findByHql(String hql);
}
