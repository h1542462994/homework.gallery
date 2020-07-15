select chenht_Students.cht_sno, cht_sname
from chenht_Students, chenht_Reports
where chenht_Students.cht_sno = chenht_Reports.cht_sno
	and chenht_Reports.cht_cno = (
		select cht_cno from chenht_Courses 
		where cht_cname like '数据库原理及其应用'
	)