package cn.edu.zjut.po;

import java.sql.Blob;

public class ItemDetail extends ItemBasic {
    private Blob image;

    public ItemDetail() {
    }

    public ItemDetail(String ISBN) {
        super(ISBN);
    }

    public ItemDetail(String ISBN, String title, String description, Float cost, Blob image) {
        super(ISBN, title, description, cost);
        this.image = image;
    }

    public Blob getImage() {
        return image;
    }

    public void setImage(Blob image) {
        this.image = image;
    }
}
