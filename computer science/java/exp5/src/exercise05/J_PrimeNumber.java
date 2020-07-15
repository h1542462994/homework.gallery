package exercise05;

import java.util.InputMismatchException;
import java.util.Scanner;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.File;

/**
 * J_PrimeNumber
 */
public class J_PrimeNumber {
    public static void main(String[] args) {
        int n = 0;
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.print("请输入一个正整数:");
            try {
                n = scanner.nextInt();
                if( n > 0 ){
                    break;
                } 
            } catch (InputMismatchException e) {
                scanner.nextLine();
                //e.printStackTrace();
            }
            System.out.println("请重新输入");
        }
        scanner.close();

        System.out.println("prime numbers");

        

        try {
            File file = new File("out.txt");
            System.out.println(file.getAbsolutePath());

            FileWriter fw = new FileWriter("out.txt");
            BufferedWriter bw = new BufferedWriter(fw);
            for(int i = 2; i < n; i++){
                if(isPrime(i)){
                    System.out.println(i);
                    bw.append(String.valueOf(i));
                    bw.newLine();
                }
            }
            bw.close();
            fw.close();
            
        } catch (IOException e) {
            e.printStackTrace();
            return;
        } 


    }

    public static boolean isPrime(int number){
        for(int i = 2; i*i <= number; i++){
            if( number % i == 0){
                return false;
            }
        }
        return true;
    }
}