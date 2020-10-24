<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/14
  Time: 10:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<html>
<head>
    <title>注册成功</title>
</head>
<body>
    <s:property value="loginUser.name"/>
    您注册成功了!
    <s:set var="user" value="loginUser" scope="session"/>

</body>
</html>
