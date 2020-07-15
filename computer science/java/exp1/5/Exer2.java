import java.util.Scanner;

public class Exer2 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String inputString = scanner.nextLine();
        StringBuilder stringBuilder = new StringBuilder();
        char c = '\0';
        int perLength = 0;
        for (int i = 0; i <= inputString.length(); i++){
            char newChar = '\0';
            if (i < inputString.length()){
                newChar = inputString.charAt(i);
            }
            if (newChar != c){
                if (perLength != 0){
                    stringBuilder.append(String.format("%s%s",c,perLength));
                }
                perLength = 0;
                c = newChar;
            }
            perLength++;
        }
        System.out.println(stringBuilder.toString());
    }
}
