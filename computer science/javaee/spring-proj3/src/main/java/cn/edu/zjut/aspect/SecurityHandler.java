package cn.edu.zjut.aspect;

import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

@Aspect
public class SecurityHandler {
    /**
     * 定义modify的Pointcut
     */
    @Pointcut("execution(* add* (..)) || execution(* del*(..)) || execution(* update*(..))")
    private void modify() {}

    @Before("modify()")
    private void checkSecurity(){
        System.out.println("---checkSecurity()---");
    }
}
