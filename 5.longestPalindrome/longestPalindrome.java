// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。

// 示例 2：
// 输入: "cbbd"
// 输出: "bb"

//Manacher算法
//i表示回文子串的中心位置，len表示回文子串的半径，则回文子串左边界为i-len,右边界为i+len
//使用一个数组arr[i]记录每个点i的最大回文串的长度,而arr[i]=
//遍历字符串时，根据i的中心位置得到最大的回文串长度，右边界为i+len，左边界为i-len
//而在求解len的过程中，由对称性，可以由左边的点的值arr[j]求出len,

//另外对于奇数和偶数个字符的字符串，先将字符串处理后再进行遍历，插入特殊字符

import java.lang.Math;

public class longestPalindrome {

    public static void main(String[] args){
        longestPalindrome test = new longestPalindrome();
        String s = "aaabaaaaaaa";
        System.out.println(test.longestPalindrome(s));
    }

    public String longestPalindrome(String s) {
        int len = s.length();
        String str = "$", result = "";
        for(int i = 0; i < len; i ++){
            str += "#" + s.charAt(i);
        }
        str += "#";
        int[] pi = new int[str.length()];
        int mx = 0, maxLen = 0, index = 0;
        for(int i = 0; i < str.length(); i ++){
            if(i < mx){
                pi[i] = Math.min(pi[2 * index - i], mx - i);
            }
            else{
                pi[i] = 1;
            }

            while(i - pi[i] >= 0 && i + pi[i] < str.length() && str.charAt(i - pi[i]) == str.charAt(i + pi[i])){
                pi[i] ++;
            }
            if(mx < pi[i] + i){
                mx = pi[i] + i;
                index = i;
            }
            if(pi[i] - 1 > maxLen){
                maxLen = pi[i] - 1;
                result = str.substring(i - pi[i] + 1, i + pi[i]).replace("#", "");
            }
        }
        return result;
    }
}