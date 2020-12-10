package cn.edu.zjut.advice;

import org.springframework.aop.MethodBeforeAdvice;
import java.lang.reflect.Method;
import java.util.Date;

public class LoggingAdvice implements MethodBeforeAdvice {
    @Override
    public void before(Method method, Object[] args, Object target) throws Throwable {
        String date1 = new Date().toString();
        System.out.println("信息： [logging before ][" + date1 + "]用户 " + args[0] + " 尝试修改个人信息...");
    }
}
