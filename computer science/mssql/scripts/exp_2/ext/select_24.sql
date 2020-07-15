select chenht_Students.cht_sname
from chenht_Students
where not exists (
	select *
	from chenht_Courses
	where not exists(
		select * 
		from chenht_Reports
		where chenht_Courses.cht_cno = chenht_Reports.cht_cno 
		and chenht_Students.cht_sno = chenht_Reports.cht_sno
	)
)