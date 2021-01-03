package cn.edu.zjut.ejb.lifecycle;

import javax.ejb.Remote;

@Remote
public interface LifeCycleRemote {
    public String hello(String name);
    public void removeSession();
}
