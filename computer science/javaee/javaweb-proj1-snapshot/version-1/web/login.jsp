<%@ page language="java" contentType="text/html; charset=GBK"
         pageEncoding="GBK"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=GBK">
  <title>�û���¼ҳ��</title>
</head>
<body>
<form id="login" action="login" method="post" onsubmit="return onLoginClick()">
  <table>
    <tbody>
      <tr>
        <td>�������û�����</td>
        <td><input name="username" type="text"></td>
      </tr>
      <tr>
        <td>���������룺</td>
        <td><input name="password" type="password"></td>
      </tr>
      <tr>
        <td colspan="2"><input type="submit" value="��¼" style="width: 100%"></td>
      </tr>
    </tbody>
  </table>

</form>
<script type="application/javascript" src="js/login.js" charset="utf-8"></script>
</body>
</html>