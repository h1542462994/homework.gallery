package store;

import dao.Pet;
import dao.PetCollection;
import dao.UserInfo;
import dao.UserPassport;

import java.util.ArrayList;

public interface IStore {
    UserInfo getInfo();

    PetCollection getPets();

    boolean login(UserPassport password);
}
