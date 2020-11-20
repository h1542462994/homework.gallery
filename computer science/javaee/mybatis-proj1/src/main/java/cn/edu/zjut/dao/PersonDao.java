package cn.edu.zjut.dao;

import cn.edu.zjut.po.Person;
import cn.edu.zjut.po.SelectPersonById;
import org.apache.ibatis.session.SqlSession;

public class PersonDao {
    public Person findById(Integer id) {
        SqlSession session = IBatisInit.get().openSession();
        Person person = session.selectOne("cn.edu.zjut.mapper.PersonMapper.findById", id);
        session.commit();
        session.close();
        return person;
    }

    public Person findById2(Integer id) {
        SqlSession session = IBatisInit.get().openSession();
        Person person = session.selectOne("cn.edu.zjut.mapper.PersonMapper.findById2", id);
        session.commit();
        session.close();
        return person;
    }

    public SelectPersonById findById3(Integer id) {
        SqlSession session = IBatisInit.get().openSession();
        SelectPersonById selectPersonById = session.selectOne("cn.edu.zjut.mapper.PersonMapper.findById3", id);
        session.commit();
        session.close();
        return selectPersonById;
    }
}
