package util;

import java.time.Instant;
import java.util.*;

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

    public Set<Integer> randInts(int start, int end, int count){
        Set<Integer> set = new HashSet<>();
        for(int i = 0; i < count; ++i){
            int rand = randInt(start, end);
            while(set.contains(rand)){
                ++rand;
                if(rand >= end) rand = start;
            }
            set.add(rand);
        }
        return set;
    }

    public int[] randDistribution(int count, int total){
        Set<Integer> rands = randInts(0, total, count);
        int[] ints = new int[total];
        for (int i = 0 ; i < total; ++i){
            if(rands.contains(i)){
                ints[i] = 1;
            } else {
                ints[i] = 0;
            }
        }

        return ints;
    }

    public void distribute(int[] array){
        for (int i = 0; i < array.length; ++i){
            int result = randInt(0, 10);
            if (result == 0){ // 10%的几率进行变换
                array[i] = 1 - array[i];
            }
        }
    }
}
