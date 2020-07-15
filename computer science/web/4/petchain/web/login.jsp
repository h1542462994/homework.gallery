<%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/13
  Time: 15:42
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="loginState" type="dao.LoginState" scope="session"/>
<html>
<head>
    <title>宠物狗</title>
    <link rel="stylesheet" href="${pageContext.servletContext.contextPath}/css/style.css">
    <link rel="stylesheet" href="${pageContext.servletContext.contextPath}/css/login.css">
</head>
<body>
    <div class="fluid">
        <div class="login-box">
            <form action="${pageContext.servletContext.contextPath}/login" method="post">
                <div class="form-row">
                    <label><input type="text" name="name" placeholder="输入账号"></label>
                    <span class="form-error-info">${loginState.passport.nameError}</span>
                </div>
                <div class="form-row">
                    <label><input type="password" name="password" placeholder="输入密码"></label>
                    <span class="form-error-info">${loginState.passport.passwordError}</span>
                </div>
                <input class="form-submit" type="submit" value="登录">
            </form>
        </div>
    </div>
</body>
</html>
