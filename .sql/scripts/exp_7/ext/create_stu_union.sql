/* init Stu_Union */
CREATE TABLE Stu_Union(Sno CHAR(8) NOT NULL UNIQUE,
			Sname CHAR(8),
			Ssex CHAR(1),
			Sage INT,
			Sdept CHAR(20),
			CONSTRAINT PK_Stu_Union PRIMARY KEY(Sno));

INSERT INTO Stu_Union VALUES('S02','王兵','M',23,'CS');
INSERT INTO Stu_union VALUES('S09','李永','M',25,'EE');
INSERT INTO Stu_union VALUES ('S03','黄浩','F',25,'EE');
INSERT INTO Stu_union VALUES ('S05','黄浩','F',25,'EE');


/* init Scholarship */
CREATE TABLE Scholarship(
    M_ID VARCHAR(10),
    Stu_id CHAR(8),
    R_Money INT,
    CONSTRAINT FK_Scholarship FOREIGN KEY(Stu_id) REFERENCES Students(Sno) /* vertify type::Sno in Students is CHAR(8) */
);

INSERT INTO Scholarship VALUES('M01','S07',5000);
INSERT INTO Scholarship VALUES('M01','S08',8000);

/* TRANSITION Example，使用事务的例子，下一个实验要用 */
SET XACT_ABORT ON
BEGIN TRANSACTION T1
INSERT INTO Stu_union VALUES('S09','李永','M',25,'EE');
INSERT INTO Stu_union VALUES ('S03','黄浩','F',25,'EE');
INSERT INTO Stu_union VALUES ('S05','黄浩','F',25,'EE');
SELECT * FROM Stu_union;
COMMIT TRANSACTION T1

