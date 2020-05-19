select chenht_Courses.cht_cname, cht_score
from chenht_Reports, chenht_Courses
where chenht_Reports.cht_cno = chenht_Courses.cht_cno and cht_sno = 'S26'
