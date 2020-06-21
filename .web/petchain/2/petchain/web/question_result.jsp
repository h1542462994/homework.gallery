<%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/13
  Time: 21:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="loginState" type="dao.LoginState" scope="session"/>
<jsp:useBean id="score" type="java.lang.Integer" scope="request"/>
<html>
<head>
    <title>Title</title>
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/style.css">
</head>
<body>
    <div class="fluid">
        <%@include file="header.jspf"%>
        <div class="section">
            恭喜你，答题获得${score}分。
            <a href="${pageContext.request.contextPath}">返回主页</a>
        </div>
    </div>
</body>
</html>
