/*
 * #naml = chenht
 * #name = cht
 * #root = 'C:\Users\t1542\Program\SQL\'
 */

/*
 * #domain = @DATEBASE('@naml_university_mis')
 */

alter table @naml_Students
    add @name_ssex char(2) not null default('男')

alter table @naml_Students
    drop constraint @name_check_scredit

alter table @naml_Courses
    alter column @name_cname char(30) not null

    
    