/* user = [admin], database = master */
/* 创建登录名 */
CREATE LOGIN USER1 WITH PASSWORD = '123456'
GO
CREATE LOGIN USER2 WITH PASSWORD = '123456'
GO
CREATE LOGIN USER3 WITH PASSWORD = '123456'
GO

/* user = [admin], database = chenht_University_Mis*/
/* 创建用户映射 */
create user USER1 for login USER1
create user USER2 for login USER2
create user USER2 for login USER3