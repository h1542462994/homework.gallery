package cn.edu.zjut.dao;

import cn.edu.zjut.model.*;
import java.sql.*;

public class DbUserDao implements UserDao {
    public static final String GET_ONE_SQL = "select * from usertable where username=? and password=? and type = ?";
    public static final String INSERT_ONE_SQL = "insert into usertable values (?,?,?)";

    public DbUserDao() {}

    public Connection getConnection() {
        Connection conn = null;
        String driver = "com.mysql.jdbc.Driver";
        String url = "jdbc:mysql://nfcv.xyz:3306/chtExpDb?useUnicode=true&characterEncoding=utf8";
        String username = "dbuser";
        String password = "dbpassword";
        try {
            Class.forName(driver);
            conn = DriverManager.getConnection(url, username, password);
        } catch (SQLException | ClassNotFoundException e){
            e.printStackTrace();
        }
        return conn;
    }

    @Override
    public boolean searchUser(UserBean user) {
        Connection conn = null;
        PreparedStatement preparedStatement = null;
        ResultSet resultSet = null;
        try {
            conn = getConnection();
            preparedStatement = conn.prepareStatement(GET_ONE_SQL);
            preparedStatement.setString(1, user.getUsername());
            preparedStatement.setString(2, user.getPassword());
            preparedStatement.setInt(3, user.getType());
            resultSet = preparedStatement.executeQuery();
            if (resultSet.next()){
                return true;
            }
        } catch (SQLException e){
            e.printStackTrace();
        } finally {
            try {
                preparedStatement.close();
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        return false;
    }

    @Override
    public boolean insertUser(UserBean user) {
        if (!UserBean.validate(user)) {
            return false;
        }
        if (searchUser(user)){
            return false;
        }

        Connection conn = null;
        PreparedStatement preparedStatement = null;

        try {
            conn = getConnection();
            preparedStatement = conn.prepareStatement(INSERT_ONE_SQL);
            preparedStatement.setString(1, user.getUsername());
            preparedStatement.setString(2, user.getPassword());
            preparedStatement.setInt(3, user.getType());
            return preparedStatement.execute();
        } catch (SQLException e){
            e.printStackTrace();
        } finally {
            try {
                preparedStatement.close();
                conn.close();
            } catch (SQLException e){
                e.printStackTrace();
            }
        }

        return false;
    }
}
