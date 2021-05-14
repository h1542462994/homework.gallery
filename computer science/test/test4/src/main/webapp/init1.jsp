<%@ page import="org.tty.test4.TestMemory" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>TestMemory</title>
</head>
<body>
<%TestMemory.runFullCopy();%>
FullCount:<%=TestMemory.fullCount%>,PartCount:<%=TestMemory.partCount%>
</body>
</html>
