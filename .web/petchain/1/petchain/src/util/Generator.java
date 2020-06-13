package util;

import java.time.Instant;
import java.util.ArrayList;
import java.util.Random;

public class Generator {
    public int randInt(int start, int end){
        Random random= new Random();
        //random.setSeed(Instant.now().toEpochMilli());
        return start +  random.nextInt(end - start);
    }

    public <T> T randSample(ArrayList<T> items){
        int index = randInt(0, items.size());
        return items.get(index);
    }
}
