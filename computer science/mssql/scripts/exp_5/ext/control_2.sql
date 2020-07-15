/* user = [admin], database = chenht_University_Mis */
grant insert,update on chenht_Students to USER1 with grant option

/* user = USER1, database = chenht_University_Mis */
/* [result] = OK */
insert into chenht_Students values 
('S09', '王小波', 'WXB@zjut.edu.cn', 19.3, '男')


/* user = USER1, database = chenht_University_Mis */
/* [result] = SELECT denied */
update chenht_Students set
cht_scredit = 18.4 where cht_sname = '王小波'