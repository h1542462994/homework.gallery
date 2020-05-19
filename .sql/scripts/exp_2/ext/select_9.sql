select cht_sno, cht_sname
from chenht_Students
where cht_sno in (
	select cht_sno from chenht_Reports
	group by cht_sno having count(cht_cno)>=3
)

select cht_sno, cht_sname
from chenht_Students, chenht_Reports
where chenht_Students.cht_sno = chenht_Reports.cht_sno
group by chenht_Students.cht_sno having count(chenht_Students.cht_sno)>=3
