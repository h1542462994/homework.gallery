package cn.edu.zjut.ejb.client;

import cn.edu.zjut.ejb.EJBFactory;
import cn.edu.zjut.ejb.lifecycle.LifeCycleRemote;

import javax.naming.NamingException;

public class LifeCycleClient {
    public static void main(String[] args) {
        try {
            EJBFactory ejbFactory = new EJBFactory();
            ejbFactory.configure();
            LifeCycleRemote lc = (LifeCycleRemote) ejbFactory.getBean(LifeCycleRemote.class.getName(), "LifeCycle", true);
            lc.hello("zjut");
            lc.removeSession();
        } catch (NamingException e) {
            e.printStackTrace();
        }
    }
}
