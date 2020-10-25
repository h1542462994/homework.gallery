<%@ taglib prefix="s" uri="/struts-tags" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>商品列表</title>
</head>
<body>
    <s:property value="#session.user"/>，您好
    <table style="border: 1px solid black">
        <tr>
            <th>编号</th>
            <th>书名</th>
            <th>说明</th>
            <th>单价</th>
        </tr>
        <s:iterator value="items">
            <tr>
                <td><s:property value="itemId"/></td>
                <td><s:property value="name"/></td>
                <td><s:property value="description"/></td>
                <td><s:property value="cost"/></td>
            </tr>
        </s:iterator>

    </table>


    <p>
        商品低于20元的商品有：<br/>
        <s:iterator value="items.{?#this.cost<20}">
        <li><s:property value="name"/>:<s:property value="cost"/>元</li>
        </s:iterator>
    </p>
    <p>
        名称为《JAVAEE 技术实验指导教程》的商品的价格为：
        <s:property value="items.{?#this.name==\"JAVAEE 技术实验指导教程\"}.{cost}[0]"/>元
    </p>

</body>
</html>
