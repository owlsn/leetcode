/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (42.86%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 60.4K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string str) {
      std::unordered_map<char, string> map;
      std::unordered_map<string, char> xmap;
      std::vector<std::string> str_vec;
      std::string s;
      for(int i = 0; i < str.length(); i ++){
        if(str[i] == ' '){
          str_vec.push_back(s);
          s = "";
        }
        else{
          s += str[i];
        }
      }
      if(s.length()){
        str_vec.push_back(s);
      }
      if(str_vec.size() != pattern.length()){
        return false;
      }
      for(int i = 0; i < pattern.length(); i ++){
        auto iter = map.find(pattern[i]);
        if(iter == map.end()){
          auto it = xmap.find(str_vec[i]);
          if(it == xmap.end()){
            map.insert({pattern[i], str_vec[i]});
            xmap.insert({str_vec[i], pattern[i]});
          }
          else{
            if(it->second != pattern[i]){
              return false;
            }
          }
        }
        else{
          if(iter->second != str_vec[i]){
            return false;
          }
        }
      }
      return true;
    }
};
// @lc code=end

