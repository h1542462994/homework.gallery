package cn.edu.zjut.bean.factory;

import cn.edu.zjut.bean.impl.ItemOrder;

public class ItemOrderFactory {
    public ItemOrder createItemOrder() {
        System.out.println("create bean ItemOrder ...");
        return new ItemOrder();
    }
}
