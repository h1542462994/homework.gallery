package cn.edu.zjut.action;

import cn.edu.zjut.bean.*;
import cn.edu.zjut.service.ItemService;
import com.opensymphony.xwork2.*;
import java.util.*;

public class ItemAction extends ActionSupport {
    public List<Item> getItems() {
        return items;
    }

    public void setItems(List<Item> items) {
        this.items = items;
    }

    private List<Item> items;

    public String getAllItems() {
        ItemService itemService = new ItemService();
        items = itemService.getAllItems();
        System.out.println("Item Action executed");
        return SUCCESS;

    }
}
