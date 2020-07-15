/* user = USER3 , database = chenht_University_Mis */
/* 授予USER3权限 */
grant insert,update on chenht_Students to USER3 with grant option

/* user = USER3 , database = chenht_University_Mis */
grant insert, update on chenht_Students to USER1

/* user = USER1 , database = chenht_University_Mis */
insert into chenht_Students values ('S11', '王小波', 'WXB@zjut.edu.cn', 18.2, '男')

/* user = USER2 , database = chenht_University_Mis */
revoke insert,update on chenht_Students from USER3 cascade

/* user = USER1 , database = chenht_University_Mis */
insert into chenht_Students values ('S11', '王小波', 'WXB@zjut.edu.cn', 18.2, '男')

/* user = [admin], database = chenht_University_Mis */
revoke insert,update on chenht_Students from USER1 cascade

/* user = USER1 , database = chenht_University_Mis */
insert into chenht_Students values ('S11', '王小波', 'WXB@zjut.edu.cn', 18.2, '男')