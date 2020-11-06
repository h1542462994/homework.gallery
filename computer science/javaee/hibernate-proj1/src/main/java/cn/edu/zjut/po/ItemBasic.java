package cn.edu.zjut.po;

public class ItemBasic {
    private String ISBN;
    private String title;
    private String description;
    private Float cost;

    public ItemBasic() {
    }

    public ItemBasic(String ISBN) {
        this.ISBN = ISBN;
    }

    public ItemBasic(String ISBN, String title, String description, Float cost) {
        this.ISBN = ISBN;
        this.title = title;
        this.description = description;
        this.cost = cost;
    }

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
}
