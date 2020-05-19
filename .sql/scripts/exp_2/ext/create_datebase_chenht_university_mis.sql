use master
go

create database chenht_university_mis
on (
    name = chenht_university_mis_data,
    filename = 'C:\Users\t1542\Program\SQL\chenht_university_mis_data.mdf',
    size = 10,
    maxsize = 50,
    filegrowth = 5
)
log on (
    name = chenht_university_mis_log,
    filename = 'C:\Users\t1542\Program\SQL\chenht_university_mis_data.ldf',
    size = 5mb,
    maxsize = 25mb,
    filegrowth = 5mb
)
go

alter database chenht_university_mis collate Chinese_PRC_CI_AS