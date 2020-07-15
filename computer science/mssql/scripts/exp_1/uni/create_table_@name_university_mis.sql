/*
 * #naml = chenht
 * #name = cht
 * #root = 'C:\Users\t1542\Program\SQL\'
 */

/*
 * #domain = @DATEBASE('@naml_university_mis')
 */

/*
 * create table [@naml_Students]
 */
create table @naml_Students(
    @name_sno char(5) primary key,
    @name_sname char(10) not null,
    @name_semail char(50),
    @name_scredit int default(0)
        constraint @name_check_scredit check(@name_scredit>=0),
    @name_sroom char(5) not null,
)

/*
 * create tbale [@naml_Teachers]
 */
create table @naml_Teachers(
    @name_tno char(5) primary key,
    @name_tname char(10) not null,
    @name_temail char(50),
    @name_tsalary int,
)

/*
 * create table [@naml_Courses]
 */
create table @naml_Courses(
    @name_cno char(5) primary key,
    @name_cname char(10) not null,
    @name_ccredit int default(0)
        constraint @name_check_ccredit check(@name_ccredit>=0),
)

/*
 *
 */
create table @naml_Reports(
    @name_sno char(5) not null,
    @name_tno char(5) not null,
    @name_cno char(5) not null,
    primary key (@name_sno, @name_tno, @name_cno),
        constraint student_reports foreign key (@name_sno) references @naml_Students,
        constraint teacher_reports foreign key (@name_tno) references @naml_Teachers,
        constraint course_report foreign key (@name_cno) references @naml_Courses
)