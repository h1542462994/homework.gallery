package cn.edu.zjut.po;

import java.io.Serializable;

public class ItemPK implements Serializable {
    private String ISBN;
    private String title;

    public String getISBN() {
        return ISBN;
    }

    public void setISBN(String ISBN) {
        this.ISBN = ISBN;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
