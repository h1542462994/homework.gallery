package service;

import bean.Item;

import java.util.ArrayList;
import java.util.List;

public class ItemService {
    public List<Item> getAllItems(){
        List<Item> items = new ArrayList<Item>();
        items.add(new Item("book001", "JAVAEE ����ʵ��ָ���̳�",
                "WEB �������֪ʶ�عˡ�" + "������ JAVAEE Ӧ�ÿ�ܡ�"
                        + "��ҵ�� EJB �����̼�����" + "JAVAEE �ۺ�Ӧ�ÿ���.", 19.95));
        items.add(new Item("book002", "JAVAEE ����",
                "Struts ��ܡ�Hibernate ��ܡ�Spring ��ܡ�"
                        + "�Ự Bean��ʵ�� Bean����Ϣ���� Bean", 29.95));
        return items;
    }
}
