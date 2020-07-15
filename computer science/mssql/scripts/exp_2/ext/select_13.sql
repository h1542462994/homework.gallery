select cht_cno
from chenht_Reports
group by cht_cno having count(cht_sno)>=2