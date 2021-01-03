package cn.edu.zjut.ejb;

import javax.ejb.Stateful;
import java.util.ArrayList;
import java.util.List;

@Stateful
public class ProductCartBean implements ProductCartRemote {
    private final ArrayList<String> cartList = new ArrayList<>();
    private int totalPrice = 0;

    @Override
    public void addProduct(String productName, int price) {
        cartList.add(productName);
        totalPrice += price;
    }

    @Override
    public List<String> listProducts() {
        return cartList;
    }

    @Override
    public int totalPrice() {
        return totalPrice;
    }
}
