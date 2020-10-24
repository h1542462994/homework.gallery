package action;

import bean.Item;
import com.opensymphony.xwork2.ActionSupport;
import service.ItemService;

import java.util.List;

public class ItemAction extends ActionSupport {
    private List<Item> items;


    public List<Item> getItems() {
        return items;
    }

    public void setItems(List<Item> items) {
        this.items = items;
    }

    public String getAllItems(){
        ItemService itemService = new ItemService();
        items = itemService.getAllItems();
        System.out.println("ItemAction executed! 执行");
        return SUCCESS;
    }
}
