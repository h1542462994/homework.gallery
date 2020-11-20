package cn.edu.zjut.dao;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.InputStream;

public class IBatisInit {
    private static IBatisInit instance;
    private SqlSessionFactory sqlSessionFactory;
    private IBatisInit(){
        try {
            InputStream config = Resources.getResourceAsStream("mybatis-config.xml");
            sqlSessionFactory =
                    new SqlSessionFactoryBuilder().build(config);
        } catch (IOException e){
            e.printStackTrace();
        }
    }
    public static IBatisInit get(){
        if (instance == null){
            instance = new IBatisInit();
        }
        return instance;
    }

    protected SqlSession openSession(){
        return sqlSessionFactory.openSession();
    }

}
