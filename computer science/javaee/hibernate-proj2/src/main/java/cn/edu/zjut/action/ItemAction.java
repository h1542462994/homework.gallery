package cn.edu.zjut.action;

import cn.edu.zjut.po.Item;
import cn.edu.zjut.service.ItemService;
import com.opensymphony.xwork2.ActionSupport;

import java.util.List;

public class ItemAction extends ActionSupport {
    private List<Object[]> items;
    private List<Object[]> others;

    public List<Object[]> getItems() {
        return items;
    }

    public void setItems(List<Object[]> items) {
        this.items = items;
    }

    public List<Object[]> getOthers() {
        return others;
    }

    public void setOthers(List<Object[]> others) {
        this.others = others;
    }

    public String findItems(){
        ItemService itemService = new ItemService();
        items = itemService.findAllTitleAndCost();
        others = itemService.findOthers();
        System.out.println("Item Action executed");
        return "success";
    }
}
