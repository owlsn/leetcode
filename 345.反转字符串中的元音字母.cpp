/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (50.12%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    38.5K
 * Total Submissions: 76.7K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
      std::set<char> sset{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
      int left = 0, right = s.length() - 1;
      char temp;
      while(left < right){
        if(sset.count(s[left]) > 0 && sset.count(s[right]) > 0){
          temp = s[left];
          s[left] = s[right];
          s[right] = temp;
          left ++;
          right --;
          continue;
        }
        if(sset.count(s[left]) > 0){
          right --;
        }
        else{
          left ++;
        }
      }
      return s;
    }
};
// @lc code=end

