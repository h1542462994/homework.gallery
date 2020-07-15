select chenht_Students.*
from chenht_Students
where chenht_Students.cht_ssex = (
	select cht_ssex
	from chenht_Students
	where cht_sno = 'S52'
)
