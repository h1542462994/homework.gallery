package exercise04;

/**
 * index查找算法
 */
public class J_IndexOf {
    public static void main(String[] args){
        String test = "kkkkkkkkkkkkkkkkkkakkkkkkbkkkkkkkkkbc";
        String key = "bc";
        
        long tick1;long tick2;
        tick1 = System.nanoTime();
        int plainIndex = plainIndexOf(test, key);
        tick2 = System.nanoTime();

        if( plainIndex == -1){
            System.out.println("No，str2中不含有str1");
        } else {
            System.out.println(String.format("Yes，str2在str1出现的起始位置为第%s个字符。",plainIndex));
        }

        System.out.println(" 朴素匹配用时" + (tick2 - tick1));

        tick1 = System.nanoTime();
        int stdIndex = test.indexOf(key);
        tick2 = System.nanoTime();
        if( stdIndex == -1){
            System.out.println("No，str2中不含有str1");
        } else {
            System.out.println(String.format("Yes，str2在str1出现的起始位置为第%s个字符。",stdIndex));
        }
        System.out.println(" 标准匹配用时" + (tick2 - tick1));

        int splitIndex = plainSplitIndexOf(test, key);

        if(splitIndex == -1){
            System.out.println("No，str2中不含有str1");
        } else {
            System.out.println(String.format("Yes，str2在str1出现的起始位置为第%s个字符。",splitIndex));
        }
    }

    public static int plainIndexOf(String str, String substr){
        char[] strChar = str.toCharArray();
        int length = strChar.length;
        char[] subStrchar = substr.toCharArray();
        int subLength = subStrchar.length;
        
        for(int i = 0; i < length - subLength + 1;i++){
            boolean flag = true;
            for(int j = 0; j < subLength; j++){
                if(strChar[i+j] != subStrchar[j]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                return i;
            }
        }
        return -1;
    }

    public static int plainSplitIndexOf(String str, String substr){
        char[] strChar = str.toCharArray();
        int length = strChar.length;
        char[] subStrchar = substr.toCharArray();
        int subLength = subStrchar.length;
        
        for(int i = 0; i < length - subLength + 1;i++){
            boolean flag = true;
            if(strChar[i] == subStrchar[0]){
                int k = 1;
                for(int j = 1; j < subLength; j++){
                    if(subStrchar[j] != strChar[i + k]){
                        --j;
                        ++k;
                    } else {
                        //test
                        //System.out.println("x=" + k);
                    }
                    if(i + k >= length){
                        flag = false;
                        break;
                    }
                }

            } else {
                flag = false;
            }

            if(flag){
                return i;
            }
        }
        return -1;
    }
}