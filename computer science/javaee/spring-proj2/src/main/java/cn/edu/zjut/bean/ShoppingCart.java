package cn.edu.zjut.bean;

import cn.edu.zjut.bean.impl.ItemOrder;

import java.util.List;

public interface ShoppingCart {
    List<ItemOrder> getItemOrders();

    void setItemOrders(List<ItemOrder> itemOrders);
}
