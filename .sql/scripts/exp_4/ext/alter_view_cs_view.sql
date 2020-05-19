create or alter view chenht_CS_View as
select * from chenht_Reports
where cht_score >= 60
with check option
