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
    <s:property value="count"/>
    <table style="border: 1px">
        <tr>
            <th>编号</th>
            <th>名称</th>
            <th>说明</th>
            <th>单价</th>
            <th>数量</th>
        </tr>
        <s:iterator value="#session.shoppingCart.itemOrderList" var="item">
            <tr>
                <td><s:property value="item.itemId"/> </td>
                <td><s:property value="item.name"/> </td>
                <td><s:property value="item.description"/> </td>
                <td><s:property value="item.cost"/> </td>
                <td><s:property value="numItems"/> </td>
            </tr>
        </s:iterator>
    </table>

</body>
</html>
