package cn.edu.zjut.service;

import cn.edu.zjut.dao.CustomerDao;
import cn.edu.zjut.po.Customer;
import com.opensymphony.xwork2.ActionContext;
import org.hibernate.Transaction;

import java.util.List;
import java.util.Map;

public class UserService {
    @SuppressWarnings({"unchecked"})
    public UserService(ActionContext context) {
        this.request = (Map<String,Object>)context.get("request");
        this.session = context.getSession();
    }

    private final Map<String,Object> request;
    private final Map<String,Object> session;

    public boolean login(Customer loginUser) {
        CustomerDao customerDao = new CustomerDao();
        String account = loginUser.getAccount();
        String password = loginUser.getPassword();
        List<Customer> list = customerDao.findByAccountAndPassword(account, password);
        if (list.isEmpty()) {
            return false;
        } else {
            session.put("user", account);
            request.put("tip", "登录成功！");
            loginUser = list.get(0);
            request.put("loginUser", loginUser);
            return true;
        }
    }

    public boolean register(Customer loginUser) {
        CustomerDao customerDao = new CustomerDao();
        if (customerDao.findByAccount(loginUser.getAccount()).isEmpty()) {
            customerDao.save(loginUser);
            session.put("loginUser", loginUser);
            return true;
        } else {
            return false;
        }
    }

    public boolean update(Customer loginUser) {
        CustomerDao customerDao = new CustomerDao();
        if (customerDao.findByAccount(loginUser.getAccount()).isEmpty()) {
            return false;
        } else {
            customerDao.update(loginUser);
            session.put("loginUser", loginUser);
            return true;
        }
    }

    public boolean delete(Customer loginUser) {
        CustomerDao customerDao = new CustomerDao();
        Transaction transaction = null;
        try {
            transaction = customerDao.getSession().beginTransaction();
            customerDao.delete(loginUser);
            transaction.commit();
            session.remove("user");
            session.put("tip", "删除个人信息成功，请重新登录");
            return true;
        } catch (Exception e) {
            if (transaction != null) transaction.rollback();
            e.printStackTrace();
            return false;
        }
    }
}
