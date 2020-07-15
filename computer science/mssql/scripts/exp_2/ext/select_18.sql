select chenht_Students.*
from chenht_Students
where cht_sno in (
	select distinct(cht_sno)
	from chenht_Reports 
)