package cn.edu.zjut.action;

import cn.edu.zjut.po.ItemBasic;
import cn.edu.zjut.service.ItemService;
import com.opensymphony.xwork2.ActionSupport;

import java.util.List;

public class ItemAction extends ActionSupport {
    private List<ItemBasic> items;

    public List<ItemBasic> getItems() {
        return items;
    }

    public void setItems(List<ItemBasic> items) {
        this.items = items;
    }

    public String allItems(){
        ItemService service = new ItemService();
        items = service.getAllItems();
        return SUCCESS;
    }
}
