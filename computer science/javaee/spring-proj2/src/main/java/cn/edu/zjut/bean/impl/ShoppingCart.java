package cn.edu.zjut.bean.impl;


import java.util.List;

public class ShoppingCart implements cn.edu.zjut.bean.ShoppingCart {
    private List<ItemOrder> itemOrders;

    @Override
    public List<ItemOrder> getItemOrders() {
        return itemOrders;
    }

    @Override
    public void setItemOrders(List<ItemOrder> itemOrders) {
        this.itemOrders = itemOrders;
    }

    @Override
    public String toString() {

        return "ShoppingCart{" +
                "itemOrders=" + itemOrders +
                '}';
    }
}
