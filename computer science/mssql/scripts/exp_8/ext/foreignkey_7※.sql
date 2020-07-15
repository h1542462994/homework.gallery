USE chenht_University_Mis
CREATE TABLE chenht_ICBC_Card(
	cht_Bank_id CHAR(20),
	cht_Stu_card_id CHAR(14),
	cht_Restored_money DECIMAL(10,2),
	constraint cht_PK_ICBC_Card PRIMARY KEY(cht_Bank_id),
	constraint cht_FK_ICBC_Card_Stu_id FOREIGN KEY(cht_Stu_card_id) REFERENCES chenht_Stu_card(cht_Card_id) ON DELETE CASCADE
)
INSERT INTO chenht_ICBC_Card VALUES('9558844022312','05212567',15000.1);
INSERT INTO chenht_ICBC_Card VALUES('9558844023645','05212222',50000.3);
SELECT * FROM chenht_ICBC_Card;
