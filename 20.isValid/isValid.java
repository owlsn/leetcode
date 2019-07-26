// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
// 有效字符串需满足：
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
// 注意空字符串可被认为是有效字符串。

// 示例 1:
// 输入: "()"
// 输出: true

// 示例 2:
// 输入: "()[]{}"
// 输出: true

// 示例 3:
// 输入: "(]"
// 输出: false

// 示例 4:
// 输入: "([)]"
// 输出: false

// 示例 5:
// 输入: "{[]}"
// 输出: true

//
import java.util.Stack;

public class isValid {

    public static void main(String[] args){
        isValid test = new isValid();
        String s = "()";
        System.out.println(test.isValid(s));
    }

    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        char temp = ' ';
        for(int i = 0; i < s.length(); i ++){
            char c = s.charAt(i);
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
                continue;
            }
            else if(c == ' '){
                continue;
            }
            else{
                if(!st.empty()){
                    temp = st.pop();
                    // System.out.println(temp);
                    // System.out.println(c);
                    if((temp == '(' && c == ')') || (c == ']' && temp == '[') || (c == '}' && temp == '{'))
                    {
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        } 
        return true;
    }
}
