package cn.edu.zjut.po;

public class Indent {
    private Integer id;
    private String name;
    private Integer num;
    private Double cost;
    private Person person;

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

    public Integer getNum() {
        return num;
    }

    public void setNum(Integer num) {
        this.num = num;
    }

    public Double getCost() {
        return cost;
    }

    public void setCost(Double cost) {
        this.cost = cost;
    }

    public Person getPerson() {
        return person;
    }

    public void setPerson(Person person) {
        this.person = person;
    }

    @Override
    public String toString() {
        return "Indent{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", num=" + num +
                ", cost=" + cost +
                ", person=" + person +
                '}';
    }
}
