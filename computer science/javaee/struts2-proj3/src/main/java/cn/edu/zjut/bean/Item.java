package cn.edu.zjut.bean;

public class Item {
    public Item(String itemId, String name, String description, double cost) {
        this.itemId = itemId;
        this.name = name;
        this.description = description;
        this.cost = cost;
    }

    private String itemId;
    private String name;
    private String description;
    private double cost;

    public String getItemId() {
        return itemId;
    }

    public void setItemId(String itemId) {
        this.itemId = itemId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public double getCost() {
        return cost;
    }

    public void setCost(double cost) {
        this.cost = cost;
    }

}
