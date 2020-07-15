create view chenht_SCT_View as 
select cht_sname, cht_cname, cht_tname from chenht_Students, chenht_Reports, chenht_Courses, chenht_Teachers
where chenht_Students.cht_sno = chenht_Reports.cht_sno 
and chenht_Courses.cht_cno = chenht_Reports.cht_cno
and chenht_Teachers.cht_tno = chenht_Reports.cht_tno