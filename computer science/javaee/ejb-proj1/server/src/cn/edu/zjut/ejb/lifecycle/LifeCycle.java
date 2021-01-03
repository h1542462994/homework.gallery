package cn.edu.zjut.ejb.lifecycle;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import javax.ejb.*;

@Stateful
public class LifeCycle implements LifeCycleRemote {
    public LifeCycle() {

    }

    public String hello(String name) {
        try {
            Thread.sleep(1000*3);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return "hello" + name + "!";
    }

    @Init
    public void initialize() {
        System.out.println("@Init 事件触发");
    }

    @PostConstruct
    public void construct() {
        System.out.println("@PostConstruct 事件触发");
    }

    @PreDestroy
    public void exit() {
        System.out.println("@PreDestroy 事件触发");
    }

    @PostActivate
    public void activate() {
        System.out.println("@PostActivate 事件触发");
    }

    @PrePassivate
    public void prePassivate() {
        System.out.println("@PrePassivate 事件触发");
    }

    @Remove
    public void removeSession() {
        System.out.println("@Remove 事件触发");
    }
}
