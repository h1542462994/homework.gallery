<%@ taglib prefix="s" uri="/struts-tags" %>
<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/11/6
  Time: 18:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>商品信息</title>
</head>
<body>
    <h1>商品列表</h1>
    <table style="border: 1px solid black">
        <tr>
            <th>编号</th>
            <th>书名</th>
            <th>说明</th>
            <th>单价</th>
        </tr>
        <s:iterator value="items">
            <tr>
                <td><s:property value="ISBN"/></td>
                <td><s:property value="title"/></td>
                <td><s:property value="description"/></td>
                <td><s:property value="cost"/></td>
            </tr>
        </s:iterator>
    </table>
</body>
</html>
