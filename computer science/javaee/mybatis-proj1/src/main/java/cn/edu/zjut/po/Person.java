package cn.edu.zjut.po;

import java.util.List;

public class Person {
    private Integer id;
    private String name;
    private Integer age;
    private IdCard idCard;
    private List<Indent> indents;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public IdCard getIdCard() {
        return idCard;
    }

    public void setIdCard(IdCard idCard) {
        this.idCard = idCard;
    }

    public List<Indent> getIndents() {
        return indents;
    }

    public void setIndents(List<Indent> indents) {
        this.indents = indents;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +
                ", idCard=" + idCard +
                ", indents=" + indents +
                '}';
    }
}
