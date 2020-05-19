/* user = USER1, database = chenht_University_Mis*/
/* USER2插入数据 */
insert into chenht_Students values ('S10', '王中波', 'WZB@zjut.edu.cn', 20.2, '男')

/* user = USER1 , database = chenht_University_Mis */
/* 授权给USER2 */
grant insert,update on chenht_Students to USER2 with grant option

/* user = USER1, database = chenht_University_Mis*/
/* USER2插入数据 */
insert into chenht_Students values ('S10', '王中波', 'WZB@zjut.edu.cn', 20.2, '男')
