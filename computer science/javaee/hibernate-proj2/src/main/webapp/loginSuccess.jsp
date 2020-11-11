<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<%@ taglib prefix="sx" uri="/struts-dojo-tags" %>
<html>
<head>
    <title>登录成功</title>

    <s:head theme="xhtml"/>
    <sx:head parseContent="true" extraLocales="UTF-8"/>
</head>
<body>
    <s:property value="#request.tip"/>
    <a href="findItems.action">查看商品信息</a>
    <s:form action="update" method="post">
        <s:hidden name="loginUser.customerId" value="%{#request.loginUser.customerId}"/>
        <s:textfield name="loginUser.account" label="用户名不能修改" value="%{#request.loginUser.account}" readonly="true"/>
        <s:textfield type="password" name="loginUser.password" label="修改密码" value="%{#request.loginUser.password}"/>
        <s:textfield name="loginUser.name" label="姓名" value="%{#request.loginUser.name}"/>
        <s:select name="loginUser.sex" list="#{0: '男', 1: '女'}" label="性别" value="%{#request.loginUser.sex}"/>
        <sx:datetimepicker name="loginUser.birthday" displayFormat="yyyy-MM-dd" label="生日" value="%{#request.loginUser.birthday}"/>
        <s:textfield name="loginUser.address" label="地址" value="%{#request.loginUser.address}"/>
        <s:textfield name="loginUser.phone" label="电话" value="%{#request.loginUser.phone}"/>
        <s:textfield name="loginUser.email" label="邮箱" value="%{#request.loginUser.password}"/>
        <s:submit value="修改"/>
    </s:form>
    <s:form action="delete" method="post">
        <s:hidden name="loginUser.customerId" value="%{#request.loginUser.customerId}"/>
        <s:submit value="删除"/>
    </s:form>
</body>
</html>
