select chenht_Students.cht_sno, cht_sname, course_count, avg_score  
into chenht_AnaReports
from
chenht_Students, (
	select cht_sno, count(*)course_count, avg(cht_score)avg_score from chenht_Reports
	group by cht_sno
)temp
where chenht_Students.cht_sno = temp.cht_sno