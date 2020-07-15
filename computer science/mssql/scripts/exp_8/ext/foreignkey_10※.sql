USE chenht_University_Mis
CREATE TABLE chenht_Listen_course(
	cht_Tno CHAR(6),
	cht_Tname VARCHAR(20),
	cht_Cno CHAR(4)
	CONSTRAINT cht_PK_listen_course PRIMARY KEY(cht_Tno)
	CONSTRAINT cht_FK_listen_course FOREIGN KEY(cht_Cno)
	REFERENCES chenht_Teach_course(cht_Cno)
)
CREATE TABLE chenht_Teach_course(
	cht_Cno CHAR(4),
	cht_Cname VARCHAR(30),
	cht_Tno CHAR(6)
	CONSTRAINT cht_PK_Teach_course PRIMARY KEY(cht_Cno)
	CONSTRAINT cht_FK_Teach_course FOREIGN KEY(cht_Tno)
	REFERENCES chenht_Listen_course(cht_Tno)
)
