<%@ taglib prefix="s" uri="/struts-tags" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>用户信息</title>
</head>
<body>
<table>
    <tr>
        <td>个人信息：</td>
    </tr>
    <tr>
        <td>用户名：</td>
        <td><s:property value="#request.loginUser.account"/></td>
    </tr>
    <s:iterator value="#request.loginUser.addresses" status="st">
        <tr>
            <td>地址<s:property value="#st.count"/>: </td>
        </tr>
        <tr>
            <td>详细地址：</td>
            <td><s:property value="detail"/> </td>
        </tr>
    </s:iterator>
    <hr>
    添加新地址： <br/>
    <s:form action="addAddr" method="post">
        <s:hidden name="loginUser.customerId" value="%{#request.loginUser.customerId}"/>
        <s:textfield name="address.detail" label="详细地址" />
        <s:textfield name="address.zipcode" label="邮政编码" />
        <s:textfield name="address.phone" label="联系电话" />
    </s:form>
</table>
</body>
</html>
