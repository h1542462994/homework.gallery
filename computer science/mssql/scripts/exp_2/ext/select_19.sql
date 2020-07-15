select chenht_Courses.cht_cno, chenht_Courses.cht_cname
from chenht_Courses
where cht_cno not in (
	select distinct(cht_cno)
	from chenht_Reports
)