USE chenht_University_Mis
CREATE Table chenht_SC(
    cht_Sno CHAR(8),
    cht_Cno CHAR(4),
    cht_Scredit INT,
    CONSTRAINT cht_PK_SC PRIMARY KEY(cht_Sno,cht_Cno),
    CONSTRAINT cht_FK_SC_Sno FOREIGN KEY(cht_Sno) REFERENCES chenht_Stu_Union (cht_Sno) ON DELETE CASCADE,
    CONSTRAINT cht_FK_SC_Cno FOREIGN KEY(cht_Cno) REFERENCES chenht_Course (cht_Cno) ON DELETE CASCADE
);
INSERT INTO chenht_SC VALUES('S02','C01',2);
INSERT INTO chenht_SC VALUES ('S02','C02',2);
INSERT INTO chenht_SC VALUES ('S01','C01',2);
INSERT INTO chenht_SC VALUES ('S01','C02',2);
SELECT * FROM chenht_SC;
