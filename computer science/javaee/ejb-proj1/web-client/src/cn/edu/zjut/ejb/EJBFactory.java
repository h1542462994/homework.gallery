package cn.edu.zjut.ejb;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;

public class EJBFactory {
    private final Hashtable<String, Object> jndiProperties = new Hashtable<>();
    private Context context;

    public void configure() throws NamingException {
        jndiProperties.put(Context.INITIAL_CONTEXT_FACTORY, "org.wildfly.naming.client.WildFlyInitialContextFactory");
        jndiProperties.put(Context.PROVIDER_URL,"http-remoting://localhost:8080");
        context = new InitialContext(jndiProperties);
    }


    /**
     * 获取一个sessionBean
     * @param beanName bean的名称
     * @param isStatefulBean 是否是有状态bean
     */
    public Object getBean(String beanTypeName, String beanName, boolean isStatefulBean) throws NamingException {
        final String appName = "";
        final String modelName = "ejb_proj1";
        final String distinctName = "";
        //final String beanName = "UserService";
        String namespace = "ejb:" + appName + "/" + modelName + "/" + distinctName + "/" + beanName + "!" + beanTypeName;
        if (isStatefulBean) {
            namespace += "?stateful";
        }
        return context.lookup(namespace);
    }
}
