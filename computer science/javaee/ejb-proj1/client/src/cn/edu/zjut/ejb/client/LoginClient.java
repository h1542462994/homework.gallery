package cn.edu.zjut.ejb.client;

import cn.edu.zjut.ejb.UserServiceRemote;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;

public class LoginClient {
    private static UserServiceRemote lookupRemoteStatelessEjbBean() throws NamingException {
        final Hashtable<String, Object> jndiProperties = new Hashtable<>();
//        jndiProperties.put(Context.URL_PKG_PREFIXES, "org.jboss.ejb.client.naming");
        jndiProperties.put(Context.INITIAL_CONTEXT_FACTORY, "org.wildfly.naming.client.WildFlyInitialContextFactory");
        jndiProperties.put(Context.PROVIDER_URL,"http-remoting://localhost:8080");
        final Context context = new InitialContext(jndiProperties);
        final String appName = "";
        final String modelName = "ejb_proj1";
        final String distinctName = "";
        final String beanName = "UserService";
        final String viewClassName = UserServiceRemote.class.getName();
        final String namespace = "ejb:" + appName + "/" + modelName + "/" + distinctName + "/" + beanName + "!" + viewClassName;
        return (UserServiceRemote) context.lookup(namespace);
    }

    public static void main(String[] args) {
        try {
            UserServiceRemote usBean = lookupRemoteStatelessEjbBean();
            System.out.println(usBean);
            boolean b1 = usBean.login("zjut", "zjut");
            System.out.println(b1);
        } catch (NamingException e){
            e.printStackTrace();
        }
    }
}
