select chenht_Teachers.cht_tno, avg(cht_score)avg_grade
from chenht_Teachers, chenht_Reports
where chenht_Teachers.cht_tno = chenht_Reports.cht_tno
group by chenht_Teachers.cht_tno
order by avg_grade desc