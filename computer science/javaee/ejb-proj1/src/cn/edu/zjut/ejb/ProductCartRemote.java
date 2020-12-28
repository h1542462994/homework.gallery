package cn.edu.zjut.ejb;

import javax.ejb.Remote;
import java.util.ArrayList;

@Remote
public interface ProductCartRemote {
    void addProduct(String productName, int price);
    ArrayList<String> listProducts();
    int totalPrice();
}
