<%--
  Created by IntelliJ IDEA.
  User: cht
  Date: 2020/10/10
  Time: 14:18
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=GBK"
         pageEncoding="GBK" import="cn.edu.zjut.model.UserBean"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=GBK">
    <title>��¼�ɹ�</title>
</head>
<body>
<% UserBean user=(UserBean)(request.getAttribute("USER")); %>
��¼�ɹ�,��ӭ��,<%=user.getUsername() %>!
</body>
</html>
