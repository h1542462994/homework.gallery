package cn.edu.zjut.test;

import cn.edu.zjut.dao.IndentDao;
import cn.edu.zjut.dao.PersonDao;
import cn.edu.zjut.po.Indent;
import cn.edu.zjut.po.Person;

public class OneToManyTest {
    public static void main(String[] args) {
        PersonDao personDao = new PersonDao();
        Person person = personDao.findById(1);
        System.out.println(person);
        System.out.println("==========================");
        IndentDao indentDao = new IndentDao();
        Indent indent = indentDao.findById(2);
        System.out.println(indent);
    }
}
