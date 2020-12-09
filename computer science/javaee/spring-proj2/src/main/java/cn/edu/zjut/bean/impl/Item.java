package cn.edu.zjut.bean.impl;

public class Item implements cn.edu.zjut.bean.Item {
    private String itemId;
    private String title;
    private String description;
    private Double cost;

    public Item(String itemId, String title, String description, Double cost) {
        this.itemId = itemId;
        this.title = title;
        this.description = description;
        this.cost = cost;
        System.out.println("create Item(" + this.itemId +").");
    }

    @Override
    public String getItemId() {
        return itemId;
    }

    @Override
    public void setItemId(String itemId) {
        this.itemId = itemId;
    }

    @Override
    public String getTitle() {
        return title;
    }

    @Override
    public void setTitle(String title) {
        this.title = title;
    }

    @Override
    public String getDescription() {
        return description;
    }

    @Override
    public void setDescription(String description) {
        this.description = description;
    }

    @Override
    public Double getCost() {
        return cost;
    }

    @Override
    public void setCost(Double cost) {
        this.cost = cost;
    }

    @Override
    public String toString() {
        return "Item{" +
                "itemId='" + itemId + '\'' +
                ", title='" + title + '\'' +
                ", description='" + description + '\'' +
                ", cost=" + cost +
                '}';
    }
}
