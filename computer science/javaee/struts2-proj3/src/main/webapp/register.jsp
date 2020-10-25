<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/25
  Time: 13:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<%@ taglib prefix="sx" uri="/struts-dojo-tags" %>
<html>
<head>
    <title>注册页面</title>

    <s:head theme="xhtml"/>
    <sx:head parseContent="true" extraLocales="UTF-8"/>
</head>
<body>
    <s:fielderror/>
    <s:actionerror/>
    <s:form action="register" method="post">
        <s:textfield name="loginUser.account" key="label.account"/>
        <s:password name="loginUser.password" key="label.password"/>
        <s:password name="loginUser.repassword" key="label.repassword"/>
        <s:textfield name="loginUser.name" key="label.name"/>
        <s:select list="#{0: '男', 1: '女'}" key="label.sex"/>
        <sx:datetimepicker name="loginUser.birthday" displayFormat="yyyy-MM-dd" key="label.birthday"/>
        <s:textfield name="loginUser.address" key="label.address"/>
        <s:textfield name="loginUser.phone" key="label.phone"/>
        <s:textfield name="loginUser.email" key="label.email"/>
        <s:submit key="register.text"/>
        <s:reset key="reset.text"/>
    </s:form>
</body>
</html>
