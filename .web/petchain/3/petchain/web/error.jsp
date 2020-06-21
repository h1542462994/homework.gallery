<%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/21
  Time: 9:22
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="loginState" type="dao.LoginState" scope="session"/>
<html>
<head>
    <title>宠物狗</title>
</head>
<body>
    <h1>登录失败</h1>
    <a href="${pageContext.servletContext.contextPath}/login">返回至登录页面。</a>
    <div>
        <div>
            <span>${loginState.passport.nameError}</span>
        </div>
        <div>
            <span>${loginState.passport.passwordError}</span>
        </div>
    </div>
</body>
</html>
