package cn.edu.zjut.dao;

import cn.edu.zjut.po.IdCard;
import org.apache.ibatis.session.SqlSession;

public class IdCardDao {
    public IdCard findById(Integer id){
        SqlSession session = IBatisInit.get().openSession();
        IdCard idCard = session.selectOne("cn.edu.zjut.mapper.IdCardMapper.findById", id);
        session.commit();
        session.close();
        return idCard;
    }
}
