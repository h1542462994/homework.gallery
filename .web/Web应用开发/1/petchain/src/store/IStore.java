package store;

import dao.Pet;
import dao.PetCollection;
import dao.UserPassport;

import java.util.ArrayList;

public interface IStore {
    PetCollection getPets();

    boolean login(UserPassport password);
}
