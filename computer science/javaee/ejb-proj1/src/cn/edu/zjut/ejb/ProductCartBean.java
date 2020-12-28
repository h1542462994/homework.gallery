package cn.edu.zjut.ejb;

import javax.ejb.Remote;
import javax.ejb.Stateful;
import java.util.ArrayList;

@Stateful
@Remote(ProductCartRemote.class)
public class ProductCartBean implements ProductCartRemote {
    private ArrayList<String> cartList = new ArrayList<>();
    private int totalPrice = 0;

    @Override
    public void addProduct(String productName, int price) {
        cartList.add(productName);
        totalPrice += price;
    }

    @Override
    public ArrayList<String> listProducts() {
        return cartList;
    }

    @Override
    public int totalPrice() {
        return totalPrice;
    }
}
