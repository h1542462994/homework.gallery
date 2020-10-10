<%@ page language="java" contentType="text/html; charset=GBK"
         pageEncoding="GBK"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=GBK">
  <title>用户登录页面</title>
</head>
<body>
<form id="login" action="login" method="post" onsubmit="return onLoginClick()">
  <table>
    <tbody>
      <tr>
        <td>用户类型:</td>
        <td>
          <select name="type">
            <option value="2">普通用户</option>
            <option value="1">管理员</option>
          </select>
        </td>
      </tr>
      <tr>
        <td>请输入用户名：</td>
        <td><input name="username" type="text"></td>
      </tr>
      <tr>
        <td>请输入密码：</td>
        <td><input name="password" type="password"></td>
      </tr>
      <tr>
        <td colspan="2"><input type="submit" value="登录" style="width: 100%"></td>
      </tr>
    </tbody>
  </table>
  <a href="register.jsp">注册新用户</a>
</form>
<script type="application/javascript" src="js/user.js" charset="utf-8"></script>
</body>
</html>