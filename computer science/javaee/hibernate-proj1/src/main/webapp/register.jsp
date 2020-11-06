<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/11/6
  Time: 20:53
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="/struts-tags" prefix="s" %>
<%@ taglib prefix="sx" uri="/struts-dojo-tags" %>
<html>
<head>
    <title>注册页面</title>

    <s:head theme="xhtml"/>
    <sx:head parseContent="true" extraLocales="UTF-8"/>
</head>
<body>
<s:form action="register" method="post">
    <s:textfield name="loginUser.account" label="请输入用户名"/>
    <s:password name="loginUser.password" label="请输入密码"/>
    <s:password name="loginUser.repassword" label="重复输入密码"/>
    <s:textfield name="loginUser.name" label="真实姓名"/>
    <s:select list="#{0: '男', 1: '女'}" label="性别"/>
    <sx:datetimepicker name="loginUser.birthday" displayFormat="yyyy-MM-dd" label="请输入生日"/>
    <s:textfield name="loginUser.contactInfo.phone" label="联系电话"/>
    <s:textfield name="loginUser.contactInfo.email" label="电子邮箱"/>
    <s:textfield name="loginUser.contactInfo.address" label="联系地址"/>
    <s:textfield name="loginUser.contactInfo.zipcode" label="邮政编码"/>
    <s:textfield name="loginUser.contactInfo.fax" label="传真"/>
    <s:submit value="注册"/>
    <s:reset value="重置"/>
</s:form>
</body>
</html>