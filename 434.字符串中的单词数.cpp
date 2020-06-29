/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (35.38%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    18.1K
 * Total Submissions: 51K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
      bool start = false;
      string temp;
      vector<string> str_vec;
      for(int i = 0; i < s.length(); i ++){
        if(!start){
          if(s[i] == ' '){
            continue;
          }
          else{
            temp += s[i];
            start = true;
          }
        }
        else{
          if(s[i] == ' '){
            if(temp.length()){
              str_vec.push_back(temp);
              temp = "";
            }
          }
          else{
            temp += s[i];
          }
        }
      }
      if(temp.length()){
        str_vec.push_back(temp);
      }
      return str_vec.size();
      // int count = 0;
      // for(int i = 0; i < s.length(); i ++){
      //   if(((i == 0) || (i != 0 && s[i - 1] == ' ')) && s[i] != ' '){
      //     count ++ ;
      //   }
      // }
      // return count;
    }
};
// @lc code=end

