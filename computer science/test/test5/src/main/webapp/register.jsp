<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>注册界面</title>
</head>
<body>
    <form action="${pageContext.request.contextPath}/register" method="post">
        <label>用户名：<input type="text" name="username"/></label>
        <label>密码：<input type="password" name="password"/></label>
        <input type="submit" value="注册"/>
    </form>
</body>
</html>
