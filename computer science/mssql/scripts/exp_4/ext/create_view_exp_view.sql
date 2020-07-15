create view chenht_EXP_View as 
select cht_sname, cht_cname, (cht_score+5)cht_score_2 
from chenht_Students, chenht_Reports, chenht_Courses
where chenht_Students.cht_sno = chenht_Reports.cht_sno
and chenht_Courses.cht_cno = chenht_Reports.cht_cno