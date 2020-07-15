update chenht_Reports
set cht_score = cht_score + 6
where cht_sno = (
	select cht_sno from chenht_Students
	where cht_sname = '刘华'
)