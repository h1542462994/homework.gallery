create table chenht_Students(
    cht_sno char(5) primary key,
    cht_sname char(100) not null,
    cht_semail char(100),
    cht_scredit float default(0)
        constraint cht_check_scredit check(cht_scredit>=0),
    cht_ssex char(2) not null default('男'),
)

create table chenht_Teachers(
    cht_tno char(5) primary key,
    cht_tname char(100) not null,
    cht_temail char(100),
    cht_tsalary int,
)

create table chenht_Courses(
    cht_cno char(5) primary key,
    cht_cname char(100) not null,
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
    cht_score int constraint cht_check_score check(cht_score>=0),
    primary key (cht_sno, cht_tno, cht_cno),
        constraint student_reports foreign key (cht_sno) references chenht_Students,
        constraint teacher_reports foreign key (cht_tno) references chenht_Teachers,
        constraint course_report foreign key (cht_cno) references chenht_Courses
)