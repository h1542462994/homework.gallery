USE chenht_University_Mis
GO
CREATE TRIGGER T1 ON chenht_Teacher
FOR INSERT, UPDATE
AS
IF (SELECT cht_Tage FROM INSERTED)< 1
BEGIN
PRINT '职工年龄必须是大于0的正数！操作失败！'
ROLLBACK TRANSACTION
END