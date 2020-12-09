package cn.edu.zjut.bean.impl;

import cn.edu.zjut.bean.Item;
import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

public class ItemOrder implements cn.edu.zjut.bean.ItemOrder, InitializingBean, DisposableBean {
    private Item item;
    private int numItems;

    public ItemOrder(){
        System.out.println("Spring constructing ItemOrder ...");
    }

    @Override
    public void increment() {
        setNumItems(getNumItems() + 1);
    }
    @Override
    public void cancel(){
        setNumItems(0);
    }
    @Override
    public double getTotalCost(){
        return getNumItems() * item.getCost();
    }

    @Override
    public Item getItem() {
        return item;
    }

    @Override
    public void setItem(Item item) {
        System.out.println("Spring injecting ItemOrder.item ...");
        this.item = item;
    }

    @Override
    public int getNumItems() {
        return numItems;
    }

    @Override
    public void setNumItems(int numItems) {
        System.out.println("Spring injecting ItemOrder.numItems");
        this.numItems = numItems;
    }

    @Override
    public String toString() {
        return "ItemOrder{" +
                "item.title=" + item.getTitle() +
                ", numItems=" + numItems +
                ", totalCost=" + getTotalCost() +
                '}';
    }

    public void init(){
        System.out.println("Spring calling init()");
    }

    public void finish(){
        System.out.println("Spring calling finish()");
    }

    @Override
    public void afterPropertiesSet() throws Exception {
        System.out.println("Spring calling afterPropertiesSet()");
    }

    @Override
    public void destroy() throws Exception {
        System.out.println("Spring calling destroy()");
    }
}
