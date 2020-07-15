-- select cht_sno, sum(cht_p) from (
--     select cht_sno, chenht_Reports.cht_cno, (1+(cht_score-60)*0.1*cht_ccredit)cht_p 
--     from chenht_Reports, chenht_Courses
--     where cht_score>=60 and chenht_Reports.cht_cno = chenht_Courses.cht_cno
--     union select cht_sno, chenht_Reports.cht_cno, (0)cht_p 
--     from chenht_Reports
--     where cht_score<60) temp
-- group by cht_sno


select cht_sno, chenht_Reports.cht_cno, cht_score, (1+(cht_score-60)*0.1*cht_ccredit)cht_p 
from chenht_Reports, chenht_Courses
where cht_score>=60 and chenht_Reports.cht_cno = chenht_Courses.cht_cno
union select cht_sno, chenht_Reports.cht_cno, cht_score, (0)cht_p 
from chenht_Reports
where cht_score<60