/*
 * #naml = chenht
 * #name = cht
 * #root = 'C:\Users\t1542\Program\SQL\'
 */

/*
 * #domain = @@serverRoot
 */

use master
go

/*
 * create database [@name_l_student_mis]
 */
create database @naml_university_mis
on (
    name = @naml_university_mis_data,
    filename = '@root@naml_university_mis_data.mdf',
    size = 10,
    maxsize = 50,
    filegrowth = 5
)
log on (
    name = @naml_university_mis_log,
    filename = '@root@naml_university_mis_data.ldf',
    size = 5mb,
    maxsize = 25mb,
    filegrowth = 5mb
)
go

alter database @naml_university_mis collate Chinese_PRC_CI_AS