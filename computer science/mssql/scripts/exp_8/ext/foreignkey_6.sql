USE chenht_University_Mis
CREATE TABLE chenht_Stu_Card(
	cht_Card_id CHAR(14),
	cht_Sno CHAR(8),
	cht_Remained_money DECIMAL(10,2),
	Constraint cht_PK_Stu_Card PRIMARY KEY(cht_Card_id),
   	Constraint cht_FK_Stu_Card_Sno FOREIGN KEY(cht_Sno) REFERENCES chenht_Students(cht_Sno) ON DELETE CASCADE
)
INSERT INTO chenht_Stu_Card VALUES('05212567','S03',400.25);
INSERT INTO chenht_Stu_Card VALUES('05212222','S09',600.50);
SELECT * FROM chenht_Stu_card;
