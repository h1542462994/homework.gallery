create view chenht_Group_View as 
select chenht_Students.cht_sno, avg(cht_score)avg_score
from chenht_Students, chenht_Reports
where chenht_Students.cht_sno = chenht_Reports.cht_sno
group by chenht_Students.cht_sno