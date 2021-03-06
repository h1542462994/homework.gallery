# Web应用开发（大二下）

## 实验1

### 实验题目

莱茨狗，百度推出区块链游戏项目，提供形态各异的虚拟宠物狗供领养，每只都有独一无二的基因。每只莱茨狗被系统冠以体型、花纹、眼睛、眼睛色、嘴巴、肚皮色、身体色、花纹色这8个外貌特征，每个特征有两种不同的属性：稀有属性和普通属性。这些属性组合起来，将会决定宠物狗最终的稀有等级，包括普通、稀有、卓越、史诗、神话、传说。

等级跟稀有属性个数对应如下：普通（1个）、稀有（2个）、卓越（3个）、史诗（4个或5个）、神话（6 个或7个）、传说（8个）。

从莱茨狗发布以来，百度搜索指数一直居高不下，这说明一直有人关注着这个游戏

基于区块链技术，可保证狗的唯一性，并对数据进行确权，令每一只数字宠物狗都不可复制，并且不可被修改和销毁。

你可以在市场中，通过数字积分——微积分，购买你心仪的莱茨狗。你也能在个人中心，查看并出售你所拥有的莱茨狗。

本实验基于百度莱茨狗为基础，构建自己的区块链交易平台，比如比特猫，芭比熊，佩齐猪等，请各位同学发挥想象力和创新力，构建某种生物（物品）的区块链交易平台

#### 1：

以百度莱茨狗为例，构建区块链交易平台首页，参考如图的结构（见下一页）

#### 2：

编写一个登录界面，用户在莱茨狗页面注册后，能根据用户名和密码进行登录（本实验默认你的姓名拼音为正确登录账号，密码为123456），通过一个servlet能实现验证，如果验证失败返回登录界面，验证成功。登录界面可参考如下

## 实验2

### 实验题目

#### 3：

新用户需要使用百度产品才能赚取微积分，用于购买莱茨狗，而在我们的实验中，微积分的赚取通过帮别人在线答题获得奖励，请参考参考2010版教材p38-p40例子（或2015版教材p34-36），设计一个在线考试网页，包含2道单选题、2道多选题、2道填空题、2道判断题，答题后能通过Servlet计算出成绩，满分100分，用户答题的分数即是他赚取的微积分，会在答题后显示：您这次赚取了**微积分

#### 4：

设计类似下图的用户静态主页，考虑到账号的安全性，因此每个账号都有密保邮箱，在用户主页中再增加一个 我的密保邮箱  超链接，点击后进入实验5

#### 5：

设计一个EmailServlet.java（servlet程序），能够查询用户的密保邮箱。在本实验中，该Servlet在web.xml中已经配置好参数（2个参数：即用户登录名和对应的密保邮箱），并已经有初始值。运行该servlet后，用户可以读取EmailServlet中已经配置好的参数并在网页上输出（可参考2010版教材程序3.3或2015版教材程序2.16）

## 实验3

### 实验题目

#### 6：

到目前为止，新创建的莱茨狗平台已经具备用户注册，登录，密保邮箱查询，免费领养，用户主页等功能，但其用户体验仍旧不够完善，现要求平台要逐步实现动态化，现阶段要实现功能包括：
1. 使用实验2的登录页面，但如果登录验证失败，需要提供失败页面error.jsp，如果登录成功跳转到InformationServlet.java
2. InformationServlet.java采用HashMap存储该用户相关的数据，包括用户登录名、领养的莱茨狗名称、莱茨狗id、莱茨狗品质（如普通、卓越等）、莱茨狗代数（即第几代莱茨狗）、莱茨狗对应的图片地址（如1.png）。InformationServlet.java将在页面上显示这些信息（如下图）

#### 7:

第0代莱茨狗特征随机算法

莱茨狗有8个外貌特征，每个特征有两种不同的属性：稀有属性和普通属性。这些属性组合起来，将会决定最终的稀有等级（普通、稀有、卓越、史诗、神话、传说）。因此，作为莱茨狗的初代，即0代的特征非常重要，现在希望通过结合人工猜数字的游戏来作为第0代莱茨狗特征随机的种子之一，其具体要求如下：

1. 先熟读参考2010版教材程序4.2或2015版教材程序3.3代码，了解猜数字游戏的原理

2. 在页面第一次运行时，生成1-100之间的一个随机数，该数我们称为 终点数。
在第一次猜数前，页面上还要给出第0代莱茨狗的初始条件（如下图），包括莱茨狗的8个基本属性，其中自定有3个属性为稀有，其他属性则为普通。

3. 在第一次猜数前，页面上还要给出第0代莱茨狗的初始条件（如下图），包括莱茨狗的8个基本属性，其中自定有3个属性为稀有，其他属性则为普通。

4. 莱茨狗的平台管理员开始猜数，每猜一次，莱茨狗的8项属性就会随机变化，变化规律为：
       （1）原本是稀有的属性，变回普通的概率是10%
       （2）原本是普通的属性，变成稀有的概率是10%
属性变化的效果要求在网页上进行显示

5. 当管理员猜对数字后，还需要在网页上显示莱茨狗的等级，等级跟稀有属性个数对应如下：普通（1个）、稀有（2个）、卓越（3个）、史诗（4个或5个）、神话（6 个或7个）、传说（8个），该第0代莱茨狗属性正式确定。

## 实验4

### 实验题目

#### 8：

狗狗集市的初步实现
在之前的实验中，平台管理员已经通过随机算法生成了第0代莱茨狗，但这些数据没有进行存储，因此管理员需要将这些数据录入到系统中，并能查看，根据此需求构建实验要求如下：      

1. 提供一种HashMap的数据结构，key包含莱茨狗的Id，value是一个String的数组，包含了名字、莱茨狗品质（如普通、卓越等）、莱茨狗代数（即第几代莱茨狗），以及8项属性是稀有还是普通（体型，花纹，眼睛，眼睛色，嘴巴，肚皮色，身体色，花纹色），莱茨狗图片地址这些字符串数据。      
2. 编写addDog.jsp，可以通过表单增加某只莱茨狗的上述字段。点击提交按钮后，跳转到一个servlet程序中。
3. 该servlet程序首先读取前一个页面表单的内容，并把信息存储在第一步的HashMap里，再将该对象存储在session作用域的属性内。然后跳转到browseDog.jsp页面
4. browseDog.jsp：该页面是狗狗集市，显示存储在session作用域内所有的莱茨狗，界面类似下图(不考虑价格)，每行显示6只
5. 点击某个莱茨狗，可以查看详情，界面可类似下图

## 实验5

### 实验题目

#### 9:

参考 2010版 p189-p193 程序7.1、7.2、7.3、7.4、7.5  （代码可从网上教学平台的《2010版教材程序代码》 中查看）并编写

但注意本次实验的数据库是远程数据库SQL SERVER2000（必须是校园网才能连）

学习如何访问远程数据库

需要注意的是：

- 访问的是SQL SERVER2000
String driver = "com.microsoft.jdbc.sqlserver.SQLServerDriver";
- 因为是远程访问数据库，请将localhost替换为172.16.13.135
String dburl = "jdbc:microsoft:sqlserver://localhost:1433;databaseName=bookstore";
- 注意数据库名称、登录名、密码必须和数据库内设置的一致（都是bookstore ）
String username = "bookstore";
String password = "bookstore";
- 远程数据库中存储的数据和p181上的数据类同，能访问bookid 为201,202,203,204,205的数据
- 需要使用sql server 2000的JDBC驱动补丁包，需要将网上教学平台内的驱动程序打包文件复制到:
Web应用程序的WEB-INF\lib目录中。
Tomcat安装目录的lib目录中