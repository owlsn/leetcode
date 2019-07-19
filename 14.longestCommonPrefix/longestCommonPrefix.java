
// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1:
// 输入: ["flower","flow","flight"]
// 输出: "fl"

// 示例 2:
// 输入: ["dog","racecar","car"]
// 输出: ""

// 解释: 输入不存在公共前缀。
// 说明:
// 所有输入只包含小写字母 a-z 。


//从头开始判断每个字符串即可


public class longestCommonPrefix {

    public static void main(String[] args){
        longestCommonPrefix test = new longestCommonPrefix();
        String[] strs = new String[]{"a"};
        System.out.println(test.longestCommonPrefix(strs));
    }

    public String longestCommonPrefix(String[] strs) {
        int len = 0;
        char c = ' ';
        if(strs.length > 0){
            while(true){
                if(len < strs[0].length()){
                    c = strs[0].charAt(len);
                }
                else{
                    c = ' ';
                }
                for(int i = 0; i < strs.length; i ++){
                    if(len >= strs[i].length() || c != strs[i].charAt(len)){
                        return strs[0].substring(0, len);
                    }
                }
                len ++ ;
            }
        }
        return "";
    }
}