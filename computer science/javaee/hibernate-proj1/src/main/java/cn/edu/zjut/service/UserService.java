package cn.edu.zjut.service;

import cn.edu.zjut.dao.CustomerDao;
import cn.edu.zjut.dao.SessionUtil;
import cn.edu.zjut.po.Customer;
import org.hibernate.Session;
import org.hibernate.Transaction;

import java.util.List;

public class UserService {
    public boolean login(Customer loginUser) {
        String account = loginUser.getAccount();
        String password = loginUser.getPassword();
        String hql = "from Customer as user where account='"
                +account+ "' and password='" + password +"'";
        CustomerDao dao = new CustomerDao();
        List<Customer> customerList = dao.findByHql(hql);
        return !customerList.isEmpty();
    }

    public void register(Customer loginUser) {
        Session session = SessionUtil.getSession();
        Transaction transaction = session.beginTransaction();
        CustomerDao dao = new CustomerDao();
        dao.save(loginUser);
        transaction.commit();
    }
}
