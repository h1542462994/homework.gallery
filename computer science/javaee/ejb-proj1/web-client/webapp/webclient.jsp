<%@ page import="java.util.Hashtable" %>
<%@ page import="javax.naming.Context" %>
<%@ page import="javax.naming.InitialContext" %>
<%@ page import="cn.edu.zjut.ejb.UserServiceRemote" %>
<%@ page import="javax.naming.NamingException" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<%
    try {
        final Hashtable<String, Object> jndiProperties = new Hashtable<>();
        jndiProperties.put(Context.INITIAL_CONTEXT_FACTORY, "org.wildfly.naming.client.WildFlyInitialContextFactory");
        jndiProperties.put(Context.PROVIDER_URL,"http-remoting://localhost:8080");
        final Context context = new InitialContext(jndiProperties);
        final String appName = "";
        final String modelName = "ejb_proj1";
        final String distinctName = "";
        final String beanName = "UserService";
        final String viewClassName = UserServiceRemote.class.getName();
        final String namespace = "ejb:" + appName + "/" + modelName + "/" + distinctName + "/" + beanName + "!" + viewClassName;
        UserServiceRemote usBean = (UserServiceRemote) context.lookup(namespace);
        System.out.println(usBean);
        if (usBean.login("zjut", "123456")){
            out.println("login ok!");
        } else {
            out.println("login failed");
        }
    } catch (NamingException e) {
        e.printStackTrace();
    }
%>
</body>
</html>
