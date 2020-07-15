select distinct(B.cht_sno)
from chenht_Reports A, chenht_Reports B
where A.cht_cno = B.cht_cno and A.cht_sno = 'S26'