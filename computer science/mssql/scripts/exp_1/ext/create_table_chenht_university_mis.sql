/*
 * #naml = chenht
 * #name = cht
 * #root = 'C:\Users\t1542\Program\SQL\'
 */

/*
 * #domain = @DATEBASE('chenht')
 */

/*
 * create table [chenht_Students]
 */
create table chenht_Students(
    cht_sno char(5) primary key,
    cht_sname char(10) not null,
    cht_semail char(50),
    cht_scredit int default(0)
        constraint cht_check_scredit check(cht_scredit>=0),
    cht_sroom char(5) not null,
)

create table chenht_Teachers(
    cht_tno char(5) primary key,
    cht_tname char(10) not null,
    cht_temail char(50),
    cht_tsalary int,
)

/*
 * create table [chenht_Courses]
 */
create table chenht_Courses(
    cht_cno char(5) primary key,
    cht_cname char(10) not null,
    cht_ccredit int default(0)
        constraint cht_check_ccredit check(cht_ccredit>=0),
)

/*
 *
 */
create table chenht_Reports(
    cht_sno char(5) not null,
    cht_tno char(5) not null,
    cht_cno char(5) not null,
    primary key (cht_sno, cht_tno, cht_cno),
        constraint student_reports foreign key (cht_sno) references chenht_Students,
        constraint teacher_reports foreign key (cht_tno) references chenht_Teachers,
        constraint course_report foreign key (cht_cno) references chenht_Courses
)