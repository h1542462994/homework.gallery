USE chenht_University_Mis
ALTER TABLE chenht_Reports DROP [cht_FK_Reports_Sno];
ALTER TABLE chenht_Reports ADD
CONSTRAINT [cht_FK_Reports_Students] FOREIGN KEY
	(
		[cht_Sno]
	) REFERENCES [dbo].[chenht_Students] (
		[cht_Sno]
	) ON DELETE CASCADE;     
DELETE FROM chenht_Students WHERE cht_Sno='S03';
SELECT * FROM chenht_Stu_card;
SELECT * FROM chenht_ICBC_Card;
