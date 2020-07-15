select cht_cno, count(*)stu_count, avg(cht_score)avg_score
from chenht_Reports
group by cht_cno