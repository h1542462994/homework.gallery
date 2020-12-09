package cn.edu.zjut.bean.impl;

import java.util.Map;

public class ShoppingCartMap {
    private Map<String, ItemOrder> itemOrders;

    public Map<String, ItemOrder> getItemOrders() {
        return itemOrders;
    }

    public void setItemOrders(Map<String, ItemOrder> itemOrders) {
        this.itemOrders = itemOrders;
    }
}
