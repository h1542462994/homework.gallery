package bean;


import java.util.ArrayList;
import java.util.List;

public class ShoppingCart {
    public ShoppingCart() {
        itemOrderList = new ArrayList<>();
        Item item = new Item("book001", "JavaEE技术实验指导课程", "WEB 程序设计知识回顾、" + "轻量级 JAVAEE 应用框架、"
                + "企业级 EJB 组件编程技术、" + "JAVAEE 综合应用开发.", 19.95);
        ItemOrder itemOrder = new ItemOrder(item);
        itemOrder.setNumItems(2);
        itemOrderList.add(itemOrder);
    }

    private List<ItemOrder> itemOrderList;

    public List<ItemOrder> getItemOrderList() {
        return itemOrderList;
    }

    public synchronized void addItem(String itemId) {
    }

    public synchronized void setNumOrdered(String itemId, int numOrdered) {
    }
}
