public class Exer1 {
    public static void main(String[] args){
        for (int i = 0;i <= 20;i++){
            for (int j = 0;j <= 33;j++){
                int k = 100 - i - j;
                if (15 * i + 9 * j + k == 300){
                    System.out.println(String.format("公鸡: %s, 母鸡：%s, 小鸡: %s",i,j,k));
                }
            }
        }
    }
}
