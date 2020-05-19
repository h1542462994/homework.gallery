ALTER TABLE chenht_ICBC_Card
DROP CONSTRAINT cht_FK_ICBC_Card_Stu_id;
ALTER TABLE chenht_ICBC_Card
ADD CONSTRAINT cht_FK_ICBC_Card_Stu_id FOREIGN KEY (cht_Stu_card_id)
REFERENCES chenht_Stu_card(cht_Card_id) ON DELETE NO ACTION;

/**在新建查询窗口中输入如下SQL语句：**/
	Begin Transaction Del
	DELETE FROM chenht_Stu_Card WHERE cht_Card_id ='05212222';
	SELECT * FROM chenht_Stu_card;
	SELECT * FROM chenht_ICBC_card;
	Commit Transaction Del

/**在新建查询窗口中输入如下SQL语句：**/
USE University_Mis
SELECT * FROM chenht_Stu_card;
SELECT * FROM chenht_ICBC_card;
