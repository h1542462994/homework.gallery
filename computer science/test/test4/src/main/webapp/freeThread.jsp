<%@ page language="java" import="org.tty.test4.*" pageEncoding="ISO-8859-1"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
    <title>free</title>
</head>
<body>
<%
    for(int i=0; i<TestCPU.threadList.size(); i++){
        TestCPU.free(TestCPU.threadList.get(i));
    }
    TestCPU.threadList.clear();
    for (int i =0; i < TestMemory.threadList.size(); i++) {
        TestMemory.free(TestMemory.threadList.get(i));
    }
    TestMemory.threadList.clear();
%>
All threads killed! <br />
Thread Counter:<%=TestCPU.threadList.size()%>
TestMemory Thread Count:<%=TestMemory.threadList.size()%>
</body>
</html>