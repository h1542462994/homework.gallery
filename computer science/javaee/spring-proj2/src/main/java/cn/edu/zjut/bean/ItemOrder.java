package cn.edu.zjut.bean;

public interface ItemOrder {
    void increment();

    void cancel();

    double getTotalCost();

    Item getItem();

    void setItem(Item item);

    int getNumItems();

    void setNumItems(int numItems);
}
