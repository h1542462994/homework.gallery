package cn.edu.zjut.advice;

import org.aopalliance.intercept.MethodInterceptor;
import org.aopalliance.intercept.MethodInvocation;

import java.util.Date;

public class LoggingInterceptor implements MethodInterceptor {
    @Override
    public Object invoke(MethodInvocation invocation) throws Throwable {
        Object[] args = invocation.getArguments();
        String date1 = new Date().toString();
        System.out.println("Interceptor 信息: [logging before][" + date1 + "]用户 " + args[0] + "尝试修改信息...");
        Object returnObject = invocation.proceed();
        String date2 = new Date().toString();
        System.out.println("Interceptor 信息: [logging after][" + date2 + "]用户 " + args[0] + "成功修改个人信息..." );
        return returnObject;
    }
}
