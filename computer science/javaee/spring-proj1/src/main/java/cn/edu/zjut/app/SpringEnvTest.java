package cn.edu.zjut.app;

import cn.edu.zjut.po.Customer;
import cn.edu.zjut.service.IUserService;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SpringEnvTest {
    public static void main(String[] args){
        // 创建spring容器
        ApplicationContext context = new ClassPathXmlApplicationContext("WEB-INF/applicationContext.xml");
        // 获取UserService实例
        IUserService userService = (IUserService) context.getBean("userService");
        Customer customer = new Customer();
        customer.setAccount("SPRING");
        customer.setPassword("SPRING");
        userService.register(customer);
    }
}
