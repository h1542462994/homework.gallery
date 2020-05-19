create table chenht_AnaReports(
    cht_sno char(5) primary key,
    cht_sname char(100) not null,
    course_count int,
    avg_score int,
    constraint cht_Students_AnaReports foreign key (cht_sno) references chenht_Students
)