select cht_cname
from chenht_Courses
where cht_ccredit in (
	select cht_ccredit
	from chenht_Courses where cht_cname = 'C++' or cht_cname = 'UML'
)