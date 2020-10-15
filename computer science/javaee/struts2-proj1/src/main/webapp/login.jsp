<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/13
  Time: 21:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<html>
<head>
    <title>登录界面</title>
</head>
<body>
    <s:i18n name="local.message" >
        <s:form action="login" method="POST">
            <s:textfield name="loginUser.account" key="login.account.lable"/>
            <s:password name="loginUser.password" key="login.password.lable"/>
            <s:submit name="submit" key="login.submit.button"/>
        </s:form>
    </s:i18n>
</body>
</html>
