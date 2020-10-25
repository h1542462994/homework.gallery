package cn.edu.zjut.service;

import cn.edu.zjut.bean.*;
import java.util.*;

public class ItemService {
    public List<Item> getAllItems() {
        List<Item> items = new ArrayList<>();
        items.add(new Item("book001", "JAVAEE 技术实验指导教程",
                "WEB 程序设计知识回顾、" + "轻量级 JAVAEE 应用框架、"
                        + "企业级 EJB 组件编程技术、" + "JAVAEE 综合应用开发.", 19.95));
        items.add(new Item("book002", "JAVAEE 技术",
                "Struts 框架、Hibernate 框架、Spring 框架、"
                        + "会话 Bean、实体 Bean、消息驱动 Bean", 29.95));
        return items;
    }
}
