package store;

import dao.Pet;
import dao.PetCollection;
import dao.UserPassport;

import java.util.ArrayList;
import java.util.HashMap;

public class Store implements IStore {
    private ArrayList<Pet> pets = new ArrayList<>();

    public Store(){
        for (int i = 0; i < 10; ++i){
            pets.add(Pet.random());
        }
    }

    @Override
    public PetCollection getPets() {
        return new PetCollection(pets);
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
