select distinct(chenht_Students.cht_sno), cht_sname
from chenht_Students, chenht_Reports 
where chenht_Reports.cht_sno = chenht_Students.cht_sno
and chenht_Reports.cht_cno in (
select cht_cno
from chenht_Courses where cht_cname = 'C++' or cht_cname = 'UML'
)