<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/13
  Time: 21:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=utf-8" language="java" pageEncoding="utf-8" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<html>
<head>
    <title>登录界面</title>
</head>
<body>
    <s:i18n name="local.message" >
        <s:actionerror/>
        <s:fielderror/>
        <s:form action="login" method="POST" validate="true">
            <s:textfield name="loginUser.account" key="label.account"/>
            <s:password name="loginUser.password" key="label.password"/>
            <s:submit name="submit" key="login.text"/>
        </s:form>
    </s:i18n>
</body>
</html>
