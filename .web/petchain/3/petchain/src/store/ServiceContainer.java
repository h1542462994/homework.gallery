package store;

import ext.ServiceContainerBase;
import ext.exception.ServiceConstructException;

import javax.servlet.ServletContext;

public class ServiceContainer extends ServiceContainerBase {
    ServiceContainer(){
        super();
        injectServices();
    }

    @Override
    protected void injectServices() {
        addSingleton(IStore.class, Store.class);
        addSingleton(IWebUrl.class, WebUrl.class);
    }

    public static void create(ServletContext context){
        instance =  new ServiceContainer();
        instance.setConfig("contextPath", context.getContextPath());
    }

    public static ServiceContainer get(){
        return (ServiceContainer)instance;
    }

    public String contextPath(){
        return (String)instance.getConfig("contextPath");
    }

    public IStore store(){
        try {
            return getService(IStore.class);
        } catch (ServiceConstructException e) {
            e.printStackTrace();
            return null;
        }
    }

    public IWebUrl webUrl(){
        try{
            return getService(IWebUrl.class);
        } catch (ServiceConstructException e) {
            e.printStackTrace();
            return null;
        }
    }
}
