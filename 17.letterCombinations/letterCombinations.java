// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//2->abc,3->def,...,7->pqrs,8->tuv,9->wxyz
// 示例:
// 输入："23"
// 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
// 说明:
// 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

// 递归表示

import java.util.HashMap;
import java.util.ArrayList;
import java.util.List;

public class letterCombinations {

    public static void main(String[] args){
        letterCombinations test = new letterCombinations();
        String str = "234";
        System.out.println(test.letterCombinations(str).toString());
    }

    public List<String> letterCombinations(String digits) {
        HashMap<Integer, String> number = new HashMap<Integer, String>();
        number.put(2, "abc");
        number.put(3, "def");
        number.put(4, "ghi");
        number.put(5, "jkl");
        number.put(6, "mno");
        number.put(7, "pqrs");
        number.put(8, "tuv");
        number.put(9, "wxyz");
        return letters(digits, number);
    }

    public List<String> letters(String digits, HashMap<Integer, String> number) {
       List<String> strs = new ArrayList<String>();
       if(digits.length() == 0){
           return strs;
       }
       else if(digits.length() == 1){
           String head = number.get(digits.charAt(0) - '0');
           for(int i = 0; i < head.length(); i ++){
               strs.add(Character.toString(head.charAt(i)));
           }
           return strs;
       }
       List<String> after =  letters(digits.substring(1), number);
    //    System.out.println(after);
       String before = number.get(digits.charAt(0) - '0');
    //    System.out.println(before);
       for(String s : after){
           for(int i = 0; i < before.length(); i ++){
               strs.add(before.charAt(i) + s);
           }
       }
       return strs;
    }
}