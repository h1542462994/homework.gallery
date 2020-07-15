USE chenht_University_Mis
CREATE TABLE chenht_Teach_course(
	cht_Cno CHAR(4),
    cht_Cname VARCHAR(30),
    cht_Tno CHAR(6)
	CONSTRAINT cht_PK_teach_course PRIMARY KEY(cht_Cno)
	CONSTRAINT cht_FK_teach_course FOREIGN KEY(cht_Tno)
	REFERENCES chenht_Listen_course(cht_Tno)
)
ALTER TABLE chenht_Listen_course 
	ADD CONSTRAINT cht_FK_listen_course FOREIGN KEY(cht_Cno)
	REFERENCES chenht_Teach_course(cht_Cno);
