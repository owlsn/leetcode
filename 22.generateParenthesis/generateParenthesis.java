// 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

// 例如，给出 n = 3，生成结果为：
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]

// 对于n和n+1的情况，可以有以下的递推
// n+1:对n的每一种情况，每一个字符位置插入一个左右括号，然后去重
// 这个方法效率比较低，但是理解起来比较直观

import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;

public class generateParenthesis {

    public static void main(String[] args){
        generateParenthesis test = new generateParenthesis();
        int n = 3;
        System.out.println(test.generateParenthesis(n));
    }

    public List<String> generateParenthesis(int n) {
        HashMap<String, Integer> map = new HashMap<String, Integer>();
        List<String> result = new ArrayList<String>();
        result = Parenthesis(n, map, new ArrayList<String>());
        return result;
    }

    public List<String> Parenthesis(int n, HashMap<String, Integer> map, List<String> result) {
        String temp = "";
        if(n > 1){
            List<String> pre = Parenthesis(n - 1, map, result);
            List<String> new_result = new ArrayList<String>();
            for(int i = 0; i < pre.size(); i ++){
                for(int j = 0; j < pre.get(i).length(); j ++){
                    // System.out.println(pre.get(i));
                    temp = pre.get(i).substring(0, j) + "()" + pre.get(i).substring(j);
                    // System.out.println("pre.get(i).substring(0, i):"+ pre.get(i).substring(0, i) + ",pre.get(i).substring(i):" + pre.get(i).substring(i));
                    if(!map.containsKey(temp)){
                        new_result.add(temp);
                        map.put(temp, 1);
                    }
                }
            }
            return new_result;
        }
        else{
            result.add("()");
            if(map.containsKey("()")){
                map.put("()", 1);
            }
        }
        return result;
    }
}