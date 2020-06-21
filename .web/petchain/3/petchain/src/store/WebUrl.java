package store;

public class WebUrl implements IWebUrl {
    ServiceContainer container;

    public WebUrl(ServiceContainer container){
        this.container = container;
    }

    @Override
    public String getUrl(String path) {
        return container.contextPath() + path;
    }

}
