<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/25
  Time: 12:27
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<html>
<head>
    <title>登录界面</title>
</head>
<body>
    <s:actionerror/>
    <s:form action="login" method="POST" validate="true">
        <s:textfield name="loginUser.account" key="label.account"/>
        <s:password name="loginUser.password" key="label.password"/>
        <s:submit name="submit" key="login.text"/>
    </s:form>
</body>
</html>
