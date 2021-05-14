<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>登录界面</title>
</head>
<body>
    <form action="${pageContext.request.contextPath}/login" method="post">
        <label>用户名：<input type="text" name="username"/></label>
        <label>密码：<input type="password" name="password"/></label>
        <input type="submit" value="登录"/>
    </form>
</body>
</html>
