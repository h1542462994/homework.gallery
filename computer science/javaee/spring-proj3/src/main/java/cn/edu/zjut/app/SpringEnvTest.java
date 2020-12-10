package cn.edu.zjut.app;

import cn.edu.zjut.po.Customer;
import cn.edu.zjut.service.UserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SpringEnvTest {
    public static void main(String[] args) {
        ApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
        UserService userService = (UserService) context.getBean("userService");
        Customer customer = new Customer();
        customer.setAccount("SPRING");
        customer.setPassword("SPRING");
        userService.addUser(customer);
    }
}
