package cn.edu.zjut.ejb;

import javax.ejb.Remote;
import java.util.List;

@Remote
public interface ProductCartRemote {
    void addProduct(String productName, int price);
    List<String> listProducts();
    int totalPrice();
}
