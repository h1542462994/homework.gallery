select R1.cht_cno, R1.cht_sno pair_1, R2.cht_sno pair_2
from chenht_Reports R1, chenht_Reports R2
where R1.cht_cno = R2.cht_cno and R1.cht_sno < R2.cht_sno