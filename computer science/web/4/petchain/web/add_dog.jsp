<%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/21
  Time: 14:52
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="loginState" type="dao.LoginState" scope="session"/>
<jsp:useBean id="addDogRequest" type="request.AddDogRequest" scope="request"/>
<html>
<head>
    <title>莱茨狗</title>
    <link rel="stylesheet" href="${pageContext.servletContext.contextPath}/css/style.css">
    <link rel="stylesheet" href="${pageContext.servletContext.contextPath}/css/login.css">
</head>
<body>
    <div class="fluid">
        <%@include file="header.jspf"%>
        <div class="main-content">
            <form action="${pageContext.servletContext.contextPath}/add_dog" method="post">
                <div class="form-row">
                    <label>宠物名称：<input type="text" name="name"></label>
                    <span class="form-error-info">${addDogRequest.nameError}</span>
                </div>
                <div>
                    <label>莱茨狗代数：<input type="number" name="batch" value="0"></label>
                    <span class="form-error-info">${addDogRequest.batchError}</span>
                </div>
                <div>
                    <label>莱茨狗图片：<input type="number" name="imageUrl" value="1" min="1" max="13" placeholder="请输入1~13中的一个数字"></label>
                    <span class="form-error-info">${addDogRequest.imageUrlError}</span>
                </div>
                <div>
                    <div>
                        <label>体型：
                            <label><input type="radio" name="attribute-0" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-0" value="1">稀有</label>
                        </label>
                    </div>
                    <div>
                        <label>花纹：
                            <label><input type="radio" name="attribute-1" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-1" value="1">稀有</label>
                        </label>
                    </div>
                    <div>
                        <label>眼睛：
                            <label><input type="radio" name="attribute-2" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-2" value="1">稀有</label>
                        </label>
                    </div>
                    <div>
                        <label>眼睛色：
                            <label><input type="radio" name="attribute-3" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-3" value="1">稀有</label>
                        </label>
                    </div>
                    <div>
                        <label>嘴巴：
                            <label><input type="radio" name="attribute-4" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-4" value="1">稀有</label>
                        </label>
                    </div>
                    <div>
                        <label>肚皮色：
                            <label><input type="radio" name="attribute-5" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-5" value="1">稀有</label>
                        </label>
                    </div>
                    <div>
                        <label>身体色：
                            <label><input type="radio" name="attribute-6" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-6" value="1">稀有</label>
                        </label>
                    </div>
                    <div>
                        <label>花纹色：
                            <label><input type="radio" name="attribute-7" value="0" checked>普通</label>
                            <label><input type="radio" name="attribute-7" value="1">稀有</label>
                        </label>
                    </div>
                </div>
                <input type="submit">
            </form>
        </div>
    </div>
</body>
</html>
