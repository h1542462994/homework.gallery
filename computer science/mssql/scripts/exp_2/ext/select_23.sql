select distinct(chenht_Students.cht_sname)
from chenht_Reports, chenht_Students
where chenht_Reports.cht_sno = chenht_Students.cht_sno
and chenht_Reports.cht_cno = 'C01'