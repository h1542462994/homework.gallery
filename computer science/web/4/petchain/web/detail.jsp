<%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/21
  Time: 16:51
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="pet" type="dao.Pet" scope="request"/>
<html>
<head>
    <title>宠物狗</title>
    <link rel="stylesheet" href="${pageContext.servletContext.contextPath}/css/style.css">
</head>
<body>
    <div class="fluid">
        <div class="main-content">
            <div class="pet" style="width: 400px">
                <div class="pet-image" style="height: 320px">
                    <img src="${pet.imageUrl}" alt="图片">
                </div>
                <div>
                    <span class="small-badge pet-level">${pet.level}</span>
                    <span class="small-badge pet-batch">第${pet.batch}代</span>
                </div>
                <div>
                    <span class="pet-name">${pet.name}</span>
                    <span class="pet-no">${pet.uid}</span>
                </div>
                <div>
                    <span class="pet-prize">${pet.prize}</span>
                </div>
                <div class="pet-attributes">
                    <div>体型：${pet.attributeForDisplay[0]}</div>
                    <div>花纹：${pet.attributeForDisplay[1]}</div>
                    <div>眼睛：${pet.attributeForDisplay[2]}</div>
                    <div>眼睛色：${pet.attributeForDisplay[3]}</div>
                    <div>嘴巴：${pet.attributeForDisplay[4]}</div>
                    <div>肚皮色：${pet.attributeForDisplay[5]}</div>
                    <div>身体色：${pet.attributeForDisplay[6]}</div>
                    <div>花纹色：${pet.attributeForDisplay[7]}</div>
                </div>
            </div>
        </div>
    </div>
</body>
</html>
