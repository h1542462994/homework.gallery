package cn.edu.zjut.po;

import java.sql.Blob;

public class Item {
    private ItemPK itemPK;
    private String description;
    private Float cost;
    private Blob image;

    public Item(){

    }

    public Item(ItemPK itemPK) {
        this.itemPK = itemPK;
    }

    public ItemPK getItemPK() {
        return itemPK;
    }

    public void setItemPK(ItemPK itemPK) {
        this.itemPK = itemPK;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Float getCost() {
        return cost;
    }

    public void setCost(Float cost) {
        this.cost = cost;
    }

    public Blob getImage() {
        return image;
    }

    public void setImage(Blob image) {
        this.image = image;
    }


}
