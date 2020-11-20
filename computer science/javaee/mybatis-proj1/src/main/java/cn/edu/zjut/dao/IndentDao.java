package cn.edu.zjut.dao;

import cn.edu.zjut.po.Indent;
import org.apache.ibatis.session.SqlSession;

import java.util.List;

public class IndentDao {
    public Indent findById(Integer id) {
        SqlSession session = IBatisInit.get().openSession();
        Indent indent = session.selectOne("cn.edu.zjut.mapper.IndentMapper.findById", id);
        session.commit();
        session.close();
        return indent;
    }

    public List<Indent> findAllByPersonId(Integer personId) {
        SqlSession session = IBatisInit.get().openSession();
        List<Indent> indents = session.selectList("cn.edu.zjut.mapper.IndentMapper.findAllByPersonId", personId);
        session.commit();
        session.close();
        return indents;
    }
}
