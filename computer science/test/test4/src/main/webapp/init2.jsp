<%@ page import="org.tty.test4.TestMemory" %><%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2021/4/14
  Time: 15:56
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>TestMemory</title>
</head>
<body>
<%TestMemory.runPartCopy();%>
FullCount:<%=TestMemory.fullCount%>,PartCount:<%=TestMemory.partCount%>
</body>
</html>
