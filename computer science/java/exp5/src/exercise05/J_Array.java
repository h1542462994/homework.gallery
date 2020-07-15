package exercise05;

import java.util.HashSet;
import java.util.Random;

/**
 * J_Array
 */
public class J_Array {
    public static void main(String[] args) {
        String[] stringArray = new String[10];
        Random random = new Random(System.nanoTime());
        for (int i = 0; i < stringArray.length; i++) {
            stringArray[i] = "hello" +  random.nextInt(20);
        }

        String linkedString = String.join("",stringArray);
        System.out.println(linkedString);

        long tick1 = 0;
        long tick2 = 0;

        tick1 = System.nanoTime();
        boolean flag = false;
        for (int i = 0; i < stringArray.length - 1; i++) {
            for (int j = i+1; j < stringArray.length; j++) {
                if(stringArray[i].equals(stringArray[j])){
                    flag = true;
                    break;
                }
            }
        }
        tick2 = System.nanoTime();
        System.out.println("time1:" + (tick2 - tick1));
        if (flag) {
            System.out.println("No equal string.");
        } else {
            System.out.println("Has equal string.");
        }

        tick1 = System.nanoTime();
        flag = false;
        HashSet<String> set = new HashSet<String>();
        for(int i = 0;i < stringArray.length; i++){
            if(!set.add(stringArray[i])){
                flag = true;
                break;
            }
        }

        tick2 = System.nanoTime();
        System.out.println("time2:" + (tick2 - tick1));
        if (flag) {
            System.out.println("No equal string.");
        } else {
            System.out.println("Has equal string.");
        }
    }
    
}