# 数据库原理及其应用（大二下）

## 实验1 数据定义

[实验报告pdf](./pdfs/1.pdf)

- 在SSMS环境中使用SQL语言创建数据库chenht_University_Mis
- 使用CREATE语句创建基本表。
- 更改基本表的定义: 增加列，删除列，修改列的数据类型。
- 创建表的升、降序索引。
- 删除基本表的约束、基本表的索引或基本表。

## 实验2 数据查询

[实验报告pdf](./pdfs/2.pdf)

- 熟悉SQL语句的数据查询语言，能够SQL语句对数据库进行单表查询、连接查询、嵌套查询、集合查询和统计查询。

## 实验3 数据更新

[实验报告pdf](./pdfs/3.pdf)

- 熟悉数据库的数据更新操作，能够使用SQL语句对数据库进行数据的插入、修改与删除操作。

## 实验4 数据视图

[实验报告pdf](./pdfs/4.pdf)

- 定义常见的视图形式，包括：
    - 行列子集视图
    - WITH CHECK OPTION的视图
    - 基于多个基表的视图
    - 基于视图的视图
    - 带表达式的视图
    - 分组视图
- 通过实验考察WITH CHECK OPTION这一语句在视图定义后产生的影响，包括对修改操作、删除操作、插入操作的影响。
- 讨论视图的数据更新情况，对子行列视图进行数据更新。
- 使用DROP语句删除一个视图，由该视图导出的其他视图定义仍在数据字典中，但已不能使用，必须显式删除。同样的原因，删除基表时，由该基表导出的所有视图定义都必须显式删除。

## 实验5 数据管理

[实验报告pdf](./pdfs/5.pdf)

- 使用GRANT语句来对用户授权，对单个用户或多个用户授权，或使用保留字PUBLIC对所有用户授权。对不同的操作对象包括数据库、视图、基本表等进行不同权限的授权。
- 使用WITH GRANT OPTION字句授予用户传播该权限的权利。
- 当在授权时发生循环授权，考察DBS能否发现这个错误。如果不能，结合取消权限操作，查看DBS对循环授权的控制。
- 使用REVOKE子句收回授权，取消授权的级联反应。

## 实验8 参照完整性

[实验报告pdf](./pdfs/8.pdf)

-	为演示参照完整性，建立表chenht_Course，令cht_Cno为其主键，并在chenht_Stu_Union中插入数据。为下面的实验步骤做预先准备。
-	建立表chenht_SC，令cht_Sno和cht_Cno分别为参照chenht_Stu_Union表以及chenht_Course表的外键，设定为级联删除，并令(cht_Sno, cht_Cno)为其主键。在不违反参照完整性的前提下，插入数据。
-	演示违反参照完整性的插入数据。
-	在chenht_Stu_Union中删除数据，演示级联删除。
-	在chenht_Course中删除数据，演示级联删除。
-	为了演示多重级联删除，建立chenht_Stu_Card表，令cht_Stu_id为参数chenht_Stu_Union表的外键，令cht_Card_id为其主键，并插入数据。
-	为了演示多重级联删除，建立chenht_ICBC_Card表，令cht_Stu_card_id为参数chenht_Stu_Union n表的外键，令cht_Card_id为其主键，并插入数据。
-	通过删除chenht_Stu_Union表中的一条记录，演示三个表的多重级联删除。
-	演示事务中进行多重级联删除失败的处理。修改chenht_ICBC_Card表的外键属性，使其变为On delete No action，演示事务中通过删除chenht_Stu_Union表中的一条记录，多重级联删除失败，整个事务回滚到事务的初始状态。
-	演示互参考问题及其解决方法。要建立教师授课和课程指定教师听课关系的两张表，规定一个教师可以授多门课，但是每个课程只能指定一个教师去听课，所以要为两张表建立相互之间的参照关系。

## 实验9 用户自定义完整性

[实验报告pdf](./pdfs/9.pdf)

-	创建chenht_Worker，chenht_Teacher表，并自定义2个约束U1以及U2，其中U1规定cht_Wname cht_Tname字段唯一，U2规定cht_Wage, chenht_Tage (级别)字段的上限是28。
-	在chenht_Worker, chenht_Teacher表中插入一条合法记录。
-	演示插入违反U2约束的例子，U2规定元组的cht_Wage,cht_Tage属性的值必须<=28。
-	去除U2约束。
-	重新插入-中想要插入的数据，由于去除了U2约束，所以插入成功。
-	创建规则cht_Rule_sex，规定插入或更新的值只能是M或F，并绑定到chenht_Worker chenht_Teacher的cht_Wsex cht_Tsex字段。
-	演示违反规则cht_Rule_sex的插入操作。

## 实验10 触发器

[实验报告pdf](./pdfs/10.pdf)

- 为chenht_Teacher表建立触发器T1，当插入或使更新表中的数据时，保证所操作的纪录的cht_Tage值大于0。
- 为chenht_Teacher表建立触发器T2，禁止删除编号为00001的CEO。
- chenht_Teacher表中的人员的编号是唯一且不可更变的，创建触发器T3实现更新中编号的不可改变性。
- 演示违反T1触发器的约束的插入操作。
- 演示违反T1触发器的约束的更新操作。
- 演示违反T2触发器的约束的插入操作。
- 演示违反T2触发器的约束的更新操作。
