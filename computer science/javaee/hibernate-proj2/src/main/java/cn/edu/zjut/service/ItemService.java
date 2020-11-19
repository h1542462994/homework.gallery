package cn.edu.zjut.service;

import cn.edu.zjut.dao.ItemDao;
import cn.edu.zjut.po.Item;

import java.util.List;

public class ItemService {
    public List<Item> findAll() {
        ItemDao itemDao = new ItemDao();
        List<Item> list = itemDao.findByHql("from Item as item");
        itemDao.getSession().close();
        return list;
    }

    public List<String> findAllTitle() {
        ItemDao itemDao = new ItemDao();
        List<String> list = itemDao.findByHql("select item.title from Item as item");
        itemDao.getSession().close();
        return list;
    }

    public List<Object[]> findAllTitleAndCost() {
        ItemDao itemDao = new ItemDao();
        List<Object[]> list = itemDao.findByHql("select item.title, item.cost from Item as item");
        itemDao.getSession().close();
        return list;
    }

    public List<Object[]> findOthers() {
        ItemDao itemDao = new ItemDao();
        List<Object[]> list = itemDao.findByHql("select item.title, item.cost from Item as item where item.cost in (select min(item.cost) from Item as item)");
        itemDao.getSession().close();
        return list;
    }
}
