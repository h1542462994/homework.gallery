package dao;

import java.util.ArrayList;
import java.util.Iterator;

public class PetCollection implements Iterable<Pet> {
    private ArrayList<Pet> pets = new ArrayList<>();
    public PetCollection(ArrayList<Pet> pets){
        this.pets = pets;
    }

    @Override
    public Iterator<Pet> iterator() {
        return pets.iterator();
    }
}
