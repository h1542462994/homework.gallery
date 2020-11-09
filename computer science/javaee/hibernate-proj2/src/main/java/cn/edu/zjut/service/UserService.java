package cn.edu.zjut.service;

import cn.edu.zjut.dao.BaseHibernateDao;
import cn.edu.zjut.dao.CustomerDao;
import cn.edu.zjut.dao.HibernateUtil;
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
        Transaction transaction = null;
        try {
            transaction = customerDao.getSession().beginTransaction();
            if (customerDao.findByAccount(loginUser.getAccount()).isEmpty()) {
                customerDao.save(loginUser);
                transaction.commit();
                customerDao.getSession().close(); // 关闭session，断开数据的连接
                session.put("loginUser", loginUser);
                request.put("tip", "注册用户成功");
                return true;
            } else {
                return false;
            }
        } catch (Exception e) {
            if (transaction != null) transaction.rollback();
            e.printStackTrace();
            request.put("tip", "注册用户失败");
            return false;
        }

    }

    public boolean update(Customer loginUser) {
        CustomerDao customerDao = new CustomerDao();
        Transaction transaction = null;
        try {
            transaction = customerDao.getSession().beginTransaction();
            customerDao.update(loginUser);
            transaction.commit();
            customerDao.getSession().close();
            session.put("loginUser", loginUser);
            request.put("tip", "更新用户信息成功");
            return true;
        } catch (Exception e) {
            if (transaction != null) transaction.rollback();
            e.printStackTrace();
            request.put("tip", "更新用户信息失败");
            return false;
        }

    }

    public boolean delete(Customer loginUser) {
        CustomerDao customerDao = new CustomerDao();
        Transaction transaction = null;
        try {
            transaction = customerDao.getSession().beginTransaction();
            customerDao.delete(loginUser);
            transaction.commit();
            customerDao.getSession().close();
            session.remove("user");
            request.put("tip", "删除个人信息成功，请重新登录");
            return true;
        } catch (Exception e) {
            if (transaction != null) transaction.rollback();
            e.printStackTrace();
            return false;
        }
    }
}
