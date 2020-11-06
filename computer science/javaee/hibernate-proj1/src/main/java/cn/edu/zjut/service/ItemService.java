package cn.edu.zjut.service;

import cn.edu.zjut.dao.ItemDao;
import cn.edu.zjut.po.ItemBasic;

import java.util.List;

public class ItemService {
    //private List<Item> items = new ArrayList<>();

    public List<ItemBasic> getAllItems() {
        ItemDao dao = new ItemDao();
        return dao.findAllBasic();
    }
}
