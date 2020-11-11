<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="s" uri="/struts-tags" %>
<html>
<head>
    <title>商品列表</title>
</head>
<body>
<h1>商品列表</h1>
<table style="border: 1px solid black">
    <tr>
        <th>书名</th>
        <th>单价</th>
    </tr>
    <s:iterator value="items" var="item">
        <tr>
            <td><s:property value="#item[0]"/></td>
            <td><s:property value="#item[1]"/></td>
        </tr>
    </s:iterator>
</table>
</body>
</html>
