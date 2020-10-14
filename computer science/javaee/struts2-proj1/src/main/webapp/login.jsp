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
    <s:form action="login" method="POST">
        <div>
            <label>请输入用户名：<s:textfield name="loginUser.account"/></label>
        </div>
        <div>
            <label>请输入密码：<s:password name="loginUser.password"/></label>
        </div>
        <s:submit/>
    </s:form>
</body>
</html>
