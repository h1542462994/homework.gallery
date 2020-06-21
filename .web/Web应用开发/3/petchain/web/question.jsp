<%--
  Created by IntelliJ IDEA.
  User: t1542
  Date: 2020/6/13
  Time: 19:41
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<jsp:useBean id="loginState" type="dao.LoginState" scope="session"/>
<html>
<head>
    <title>宠物狗</title>
    <link rel="stylesheet" href="${pageContext.servletContext.contextPath}/css/style.css">
</head>
<body>
<div class="fluid">
    <%@include file="header.jspf"%>
    <div class="main-content">
        <div class="section">
            <p>一起赚取微积分吧！</p>
            <form action="${pageContext.servletContext.contextPath}/question" method="post">
                <div>
                    <span>单选题</span>
                    <div>
                        <p><span class="score-badge">10分</span>1、在植物的叶绿体中，那个属于光反应发生的场所？</p>
                        <label><input type="radio" name="answer1" value="0">类囊体膜</label>
                        <label><input type="radio" name="answer1" value="1">白质</label>
                        <label><input type="radio" name="answer1" value="2">叶绿体基质</label>
                    </div>
                    <div>
                        <p><span class="score-badge">10分</span>1、如果使用具有放射性的氧18标记的水进行植物的光合作用实验，并给予短暂的光照，则最先出现放射性的物质是？</p>
                        <label><input type="radio" name="answer2" value="0">二氧化碳</label>
                        <label><input type="radio" name="answer2" value="1">氧气</label>
                        <label><input type="radio" name="answer2" value="2">水</label>
                    </div>
                </div>
                <div>
                    <span>多选题</span>
                    <div>
                        <p><span class="score-badge">20分</span>1、在菠菜的叶绿素纸层析实验中，依次出现的4条色带分别为什么物质：</p>
                        <label><input type="checkbox" name="answer3" value="0">叶绿素a</label>
                        <label><input type="checkbox" name="answer3" value="1">叶绿素b</label>
                        <label><input type="checkbox" name="answer3" value="2">胡萝卜素</label>
                        <label><input type="checkbox" name="answer3" value="3">叶黄素</label>
                        <label><input type="checkbox" name="answer3" value="4">叶青素</label>
                        <label><input type="checkbox" name="answer3" value="5">番茄红素</label>
                    </div>
                    <div>
                        <p><span class="score-badge">20分</span>2、在RNA中，有以下4种碱基：</p>
                        <label><input type="checkbox" name="answer4" value="0">A（腺嘌呤）</label>
                        <label><input type="checkbox" name="answer4" value="1">G（鸟嘌呤）</label>
                        <label><input type="checkbox" name="answer4" value="2">T（胸腺嘧啶）</label>
                        <label><input type="checkbox" name="answer4" value="3">U（尿嘧啶）</label>
                        <label><input type="checkbox" name="answer4" value="4">C（胞嘧啶）</label>
                    </div>
                </div>
                <div>
                    <span>填空题</span>
                    <div>
                        <p><span class="score-badge">10分</span>1、人体中所占比重最大的元素是：<label><input type="text" name="answer5" required></label></p>

                    </div>
                    <div>
                        <p><span class="score-badge">10分</span>2、地球上最大的生态系统称为：<label><input type="text" name="answer6" required></label></p>

                    </div>
                </div>
                <div>
                    <span>判断题</span>
                    <div>
                        <p><span class="score-badge">10分</span><label><input type="checkbox" name="answer7" value="0"></label>1、植物的所有细胞均含有叶绿体。</p>

                    </div>
                    <div>
                        <p><span class="score-badge">10分</span><label><input type="checkbox" name="answer8" value="0"></label>2、植物细胞处在高浓度的溶液环境下会发生质壁分离现象。</p>

                    </div>
                </div>
                <input type="submit" value="提交">
            </form>
        </div>
    </div>
</div>
</body>
</html>
