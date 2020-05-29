use chenht_University_Mis
create table chenht_Teacher(
    cht_Tno char(5),
    cht_Tname char(8) constraint U1 unique,
    cht_Tsex char(1),
    cht_Tage int constraint U2 check(cht_Tage <= 28),
    cht_Tdept char(20),
    constraint PK_Teacher primary key (cht_Tno)
)