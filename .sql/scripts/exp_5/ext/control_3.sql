/* user = [admin], database = chenht_University_Mis */
/* 授权USER2 */
grant insert, update(cht_score), select(cht_tno, cht_cno, cht_score) 
on chenht_Reports to USER2

/* user = USER2, database = chenht_University_Mis */
/* insert :> chenht_Reports with USER2 */
insert into chenht_Reports
values ('S09', 'T01', 'C01', 93)

/* user = USER2, database = chenht_University_Mis */
/* update :> with USER2 */
update chenht_Reports set cht_score = 93
where cht_sno = 'S09' and cht_cno = 'C01'

/* user = USER2, database = chenht_University_Mis */
/* update :> chenht_Reports with USER2 */
update chenht_Reports set cht_score = cht_score + 1 where cht_score < 100 and cht_cno = 'C01'

/* user = USER2, database = chenht_University_Mis */
/* select :> chenht_Reports with USER2 */
select cht_cno, count(*)re_count, avg(cht_score)avg_score 
from chenht_Reports
group by cht_cno