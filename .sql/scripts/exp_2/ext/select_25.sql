select chenht_Students.*
from chenht_Students where chenht_Students.cht_sno in (
	select chenht_Reports.cht_sno from chenht_Reports where chenht_Reports.cht_cno in (
		select cht_cno from chenht_Courses
		where cht_cname = 'C++' or cht_cname = 'JAVA'
	)
)