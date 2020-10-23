<%@ taglib prefix="s" uri="/struts-tags" %>
<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/13
  Time: 21:16
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" %>
<html>
<head>
    <title>登录成功</title>
</head>
<body>
    <s:actionmessage/>
    本站访问次数为：<s:property value="#application.counter"/><br/>
    <s:property value="#session.user"/>,
    <s:property value="#request.tip"/>
</body>
</html>
