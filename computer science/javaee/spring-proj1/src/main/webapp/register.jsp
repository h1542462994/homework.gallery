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
    <s:textfield name="loginUser.account" label="账号"/>
    <s:password name="loginUser.password" label="密码"/>
    <s:textfield name="loginUser.name" label="姓名"/>
    <s:select name="loginUser.sex" list="#{0: '男', 1: '女'}" label="性别"/>
    <sx:datetimepicker name="loginUser.birthday" displayFormat="yyyy-MM-dd" label="生日"/>
    <s:textfield name="loginUser.address" label="联系地址"/>
    <s:textfield name="loginUser.phone" label="电话号码"/>
    <s:textfield name="loginUser.email" label="电子邮箱"/>
    <s:submit label="注册"/>
    <s:reset label="重置"/>
</s:form>
</body>
</html>