insert chenht_Stu_Union values ('S01','李用','0',24,'FF')
select * from chenht_Stu_Union
create table chenht_Course (
	cht_cno char(4) not null unique,
	cht_cname varchar(50) not null,
	cht_cpoints int,
	constraint cht_PK primary key(cht_cno)
)
insert into chenht_Course values ('C01', 'ComputerNetworks', 2)
insert into chenht_Course values ('C02', 'ArtificialIntelligence', 3)