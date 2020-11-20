package cn.edu.zjut.test;

import cn.edu.zjut.dao.PersonDao;
import cn.edu.zjut.po.Person;
import cn.edu.zjut.po.SelectPersonById;

public class OnoToOneTest {
    public static void main(String[] args) {
        PersonDao personDao = new PersonDao();
        Person p1 = personDao.findById(1);
        System.out.println(p1);
        System.out.println("=========================");
        Person p2 = personDao.findById2(1);
        System.out.println(p2);
        System.out.println("=========================");
        SelectPersonById p3 = personDao.findById3(1);
        System.out.println(p3);
    }
}
