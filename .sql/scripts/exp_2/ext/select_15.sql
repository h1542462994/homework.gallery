select chenht_Students.*,chenht_Reports.cht_cno, chenht_Reports.cht_score
from chenht_Reports, chenht_Students
where chenht_Students.cht_sno = chenht_Reports.cht_sno
order by chenht_Students.cht_sno