package cn.edu.zjut.service;

import cn.edu.zjut.dao.CustomerDao;
import cn.edu.zjut.po.Address;
import cn.edu.zjut.po.Customer;
import com.opensymphony.xwork2.ActionContext;
import org.hibernate.Transaction;

import java.util.Map;

@SuppressWarnings({"unchecked"})
public class UserService {
    public UserService(ActionContext context){
        this.context = context;
    }
    private final ActionContext context;
    private final CustomerDao customerDao = new CustomerDao();
    public boolean login(Customer loginUser){
        Customer user = customerDao.findByAccount(loginUser.getAccount());
        if (user == null)
            return false;
        if (!user.getPassword().equals(loginUser.getPassword())) {
            return false;
        }
        return true;
    }

    public boolean addAddress(Customer loginUser, Address address){
        Map<String,Object> request = (Map<String, Object>) context.get("request");
        loginUser = customerDao.find(loginUser.getCustomerId());
        address.setCustomer(loginUser); //注释1
        Transaction transaction = null;
        try {
            transaction = customerDao.getSession().beginTransaction();
            customerDao.update(loginUser);
            transaction.commit();
            request.put("loginUser", loginUser);
            request.put("tip", "添加地址成功");
            return true;
        } catch (Exception e) {
            if (transaction != null) transaction.rollback();
            return false;
        } finally {
            customerDao.getSession().close();
        }
    }
}
