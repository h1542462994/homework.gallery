/*
 * #naml = chenht
 * #name = cht
 * #root = 'C:\Users\t1542\Program\SQL\'
 */

/*
 * #domain = @DATEBASE('chenht_university_mis')
 */

alter table chenht_Students
    add cht_ssex char(2) not null default('男')

alter table chenht_Students
    drop constraint cht_check_scredit

alter table chenht_Courses
    alter column cht_cname char(30) not null

    
    