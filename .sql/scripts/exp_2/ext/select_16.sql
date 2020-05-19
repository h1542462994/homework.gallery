select chenht_Students.cht_sname, chenht_Courses.cht_cname, chenht_Reports.cht_score
from chenht_Reports, chenht_Courses, chenht_Students
where chenht_Reports.cht_cno = chenht_Courses.cht_cno 
and chenht_Students.cht_sno = chenht_Reports.cht_sno
and chenht_Students.cht_sno = 'S52'
