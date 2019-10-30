package exercise04;

import java.util.Random;

/**
 * J_Array
 */
public class J_Array {
    public static void main(String[] args) {
        String[] stringArray = new String[10];
        Random random = new Random(System.nanoTime());
        for (int i = 0; i < stringArray.length; i++) {
            stringArray[i] = "hello" +  random.nextInt(25);
        }

        String linkedString = String.join("",stringArray);
        System.out.println(linkedString);

        boolean flag = false;
        for (int i = 0; i < stringArray.length - 1; i++) {
            for (int j = i+1; j < stringArray.length; j++) {
                if(stringArray[i].equals(stringArray[j])){
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            System.out.print("No equal string.");
        } else {
            System.out.println("Has equal string.");
        }
    }
    
}