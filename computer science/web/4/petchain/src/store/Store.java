package store;

import dao.Pet;
import dao.PetCollection;
import dao.UserInfo;
import dao.UserPassport;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Store implements IStore {
    private ArrayList<Pet> pets = new ArrayList<>();

    @Override
    public UserInfo getInfo() {
        return info;
    }
    @Override
    public PetCollection getPets() {
        return new PetCollection(pets);
    }

    private UserInfo info = new UserInfo();

    public Store(){
        for (int i = 0; i < 10; ++i){
            pets.add(Pet.random());
        }
        info.setName("cht");
        info.setCoins(1000.0);
        info.setEmail("cht@outlook.com");
        info.setPets(new PetCollection(Pet.randoms(2)));
    }

    @Override
    public boolean login(UserPassport password){
        if(!"cht".equals(password.getName())){
            password.setNameError("不存在的用户");
            return false;
        } else if(!"123456".equals(password.getPassword())) {
            password.setPasswordError("密码错误");
            return false;
        }
        return true;
    }
}
