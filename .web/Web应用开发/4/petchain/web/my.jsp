<%@ page import="dao.Pet" %><%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/13
  Time: 21:31
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="loginState" type="dao.LoginState" scope="session"/>
<jsp:useBean id="userInfo" type="dao.UserInfo" scope="request"/>
<html>
<head>
    <title>宠物狗</title>
    <link rel="stylesheet" href="${pageContext.request.contextPath}/css/style.css">
</head>
<body>
    <div class="fluid">
        <%@include file="header.jspf"%>
        <div class="main-content">
            <div class="user-info">
                <div><span class="small-badge user-name">${userInfo.name}</span>&nbsp;&nbsp;<a href="${pageContext.request.contextPath}/email">密保邮箱</a></div>
                <div><span class="user-coins">${userInfo.coins}微积分</span></div>
            </div>
            <div class="cards">
                <% for(Pet pet: userInfo.getPets()) {%>
                <div class="pet">
                    <div class="pet-image">
                        <img src="<%=pet.getImageUrl()%>" alt="宠物照片">
                    </div>
                    <div>
                        <span class="small-badge pet-level"><%=pet.getLevel()%></span>
                        <span class="small-badge pet-batch">第<%=pet.getBatch()%>代</span>
                    </div>
                    <div>
                        <span class="pet-name"><%=pet.getName()%></span>
                        <span class="pet-no"><%=pet.getUid()%></span>
                    </div>
                    <div>
                        <span class="pet-prize"><%=pet.getPrize()%></span>
                    </div>
                </div>
                <% }%>
            </div>
        </div>
        <div class="bottom-nav">
            <a href="${pageContext.request.contextPath}"><span>狗狗集市</span></a>
            <a href="#"><span class="selected">我的狗窝</span></a>
        </div>
    </div>
</body>
</html>
