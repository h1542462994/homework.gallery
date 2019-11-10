package exercise05;

import java.util.*;

/**
 * J_HashFor
 */
public class J_HashFor {
    public static void main(String[] args){
        for(int i = 0; i < 1000 ; i+=20){
            System.out.print("i:" + i + "  ");
            testTime(i);
        }
    }

    public static void testTime(int j){
        int sizen = 1000;
        //int j = 500;
        float key = 0;
        float[] arr = new float[sizen];
        Map map = new HashMap();
        Random ran = new Random();
        for (int i = 0; i < sizen; i++) {
            float next = ran.nextFloat();
            arr[i] = next;
            map.put(i, next);
            if(i == j){
                key = next;
            }
        }

        long tick1 = 0;
        long tick2 = 0;
        tick1 = System.nanoTime();
        boolean flag = false;
        for(int i = 0; i < sizen;i++){
            if(arr[i] == key){
                flag = true;
                break;
            }
        }
        tick2 = System.nanoTime();
        System.out.print("time1:" + (tick2 - tick1) + "  ");

        tick1 = System.nanoTime();
        float v = (float)map.get(j);
        tick2 = System.nanoTime();
        System.out.println("time2:" + (tick2 - tick1));
    }
    
}