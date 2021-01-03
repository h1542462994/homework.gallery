<%@ page import="java.util.Hashtable" %>
<%@ page import="javax.naming.Context" %>
<%@ page import="javax.naming.InitialContext" %>
<%@ page import="cn.edu.zjut.ejb.UserServiceRemote" %>
<%@ page import="javax.naming.NamingException" %>
<%@ page import="cn.edu.zjut.ejb.EJBFactory" %>
<%@ page import="java.io.PrintWriter" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>EJB实验，登录</title>
</head>
<body>
<%
    try {
        EJBFactory ejbFactory = new EJBFactory();
        ejbFactory.configure();
        UserServiceRemote usBean = (UserServiceRemote) ejbFactory.getBean(UserServiceRemote.class.getName(), "UserService", false);
        if (usBean.login("zjut", "zjut")){
            out.println("login OK!");
        } else {
            out.println("login Failed!");
        }
    } catch (NamingException e) {
        e.printStackTrace();
    }
%>
</body>
</html>
