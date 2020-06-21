package util;

public class Checker {
    public static String checkName(String value){
        if(value == null)
            return "不能为空";
        if(value.length() < 2){
            return "长度应不小于2个字符";
        } else if(value.length() > 20){
            return "长度应不小于20个字符";
        }
        return null;
    }

    public static String checkBatch(String value){
        try{
            if (value == null)
                return "不能为空";
            if(Integer.parseInt(value) < 0){
                return "不能为负数";
            }
            return null;
        } catch (NumberFormatException e){
            return "不是数字";
        }

    }

}
