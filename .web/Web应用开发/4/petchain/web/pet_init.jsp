<%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/21
  Time: 10:01
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="loginState" type="dao.LoginState" scope="session"/>
<jsp:useBean id="petInit" type="dao.PetInit" scope="session"/>
<html>
<head>
    <title>莱茨狗</title>
    <link rel="stylesheet" href="${pageContext.servletContext.contextPath}/css/style.css">
</head>
<body>
    <div class="fluid">
        <%@include file="header.jspf"%>
        <div class="main-content">
            <div class="guess-result">${petInit.guessResult}</div>
            <div class="pet-attribute-title">属性</div>
            <div class="pet-attributes">
                <div>体型：${petInit.pet.attributeForDisplay[0]}</div>
                <div>花纹：${petInit.pet.attributeForDisplay[1]}</div>
                <div>眼睛：${petInit.pet.attributeForDisplay[2]}</div>
                <div>眼睛色：${petInit.pet.attributeForDisplay[3]}</div>
                <div>嘴巴：${petInit.pet.attributeForDisplay[4]}</div>
                <div>肚皮色：${petInit.pet.attributeForDisplay[5]}</div>
                <div>身体色：${petInit.pet.attributeForDisplay[6]}</div>
                <div>花纹色：${petInit.pet.attributeForDisplay[7]}</div>
            </div>
            <div>
                当前等级：${petInit.pet.level}
            </div>
            <% if (petInit.getGuessed()) {%>
            <a href="${pageContext.servletContext.contextPath}/">返回主页</a>
            <% } else {%>
            <form action="${pageContext.servletContext.contextPath}/pet_init" method="post">
                <label><input type="text" name="number" placeholder="请输入0-99的一个数字"></label>
                <input type="submit">
            </form>
            <% }%>
        </div>
    </div>

</body>
</html>
