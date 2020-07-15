create view chenht_VV_View as 
select cht_sno, count(cht_cno)course_count, avg(cht_score)avg_score
from chenht_CS_View
group by cht_sno