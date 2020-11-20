package cn.edu.zjut.test;

import cn.edu.zjut.po.MapUser;
import cn.edu.zjut.po.MyUser;
import cn.edu.zjut.po.UserParam;
import org.apache.commons.logging.*;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.*;

import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class MyBatisTest {
    public static void main(String[] args) {
        try {
            Log log = LogFactory.getLog(MyBatisTest.class);
            InputStream config = Resources.getResourceAsStream("mybatis-config.xml");
            SqlSessionFactory sqlSessionFactory =
                    new SqlSessionFactoryBuilder().build(config);
            // 创建一个session
            SqlSession session = sqlSessionFactory.openSession();

            MapUser mapUser = new MapUser();
            mapUser.setM_uname("张三");
            mapUser.setM_usex("男");
            int rowEffect = session.insert("cn.edu.zjut.mapper.UserMapper.addUserMap", mapUser);
            System.out.println(rowEffect);
            List<MapUser> list = session.selectList("cn.edu.zjut.mapper.UserMapper.selectAllUser");
            mapUser = list.get(list.size() -1 );
            mapUser.setM_uname("李四");
            rowEffect = session.update("cn.edu.zjut.mapper.UserMapper.updateUserMap", mapUser);
            System.out.println(rowEffect);

            session.commit();
            session.close();

        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
