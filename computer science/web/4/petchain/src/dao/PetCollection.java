package dao;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.concurrent.atomic.AtomicReference;

public class PetCollection implements Iterable<Pet> {
    ArrayList<Pet> pets;

    public PetCollection(ArrayList<Pet> pets){
        this.pets =pets;
    }

    public boolean add(Pet pet){
        return pets.add(pet);
    }

    public Pet find(String id){
        for (Pet pet: pets){
            if (pet.getUid().equals(id)) return pet;
        }
        return null;
    }

    @Override
    public Iterator<Pet> iterator() {
        return pets.iterator();
    }
}
