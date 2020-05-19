delete from chenht_Reports
where cht_cno = (
	select cht_cno from chenht_Courses
	where cht_cname = 'Java'
)