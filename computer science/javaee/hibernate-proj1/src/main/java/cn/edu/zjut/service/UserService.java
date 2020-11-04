package cn.edu.zjut.service;

import cn.edu.zjut.dao.CustomerDao;
import cn.edu.zjut.po.Customer;

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
}
