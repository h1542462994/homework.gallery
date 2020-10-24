<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/24
  Time: 15:11
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" pageEncoding="UTF-8" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<html>
<head>
    <title>商品列表</title>
</head>
<body>
    <table style="border: 1px">
        <tr>
            <th>编号</th>
            <th>名称</th>
            <th>说明</th>
            <th>单价</th>
            <th>数量</th>
        </tr>
        <s:iterator value="items">
            <tr>
                <td><s:property value="itemId"/> </td>
                <td><s:property value="name"/> </td>
                <td><s:property value="description"/> </td>
                <td><s:property value="cost"/> </td>
            </tr>
        </s:iterator>
    </table>
</body>
</html>
