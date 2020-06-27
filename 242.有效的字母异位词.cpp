/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (60.26%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    110.2K
 * Total Submissions: 182.8K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length() != t.length()){
        return false;
      }
      std::unordered_map<char, int> str_map;
      for(int i = 0; i < s.length(); i ++){
        auto iter = str_map.find(s[i]);
        if(iter == str_map.end()){
          str_map.insert({s[i], 1});
        }
        else{
          iter->second ++;
        }
        auto it = str_map.find(t[i]);
        if(it == str_map.end()){
          str_map.insert({t[i], -1});
        }
        else{
          it->second --;
        }
      }
      for(auto iter = str_map.begin(); iter != str_map.end(); iter ++){
        if(iter->second != 0){
          return false;
        }
      }
      return true;
    }
};
// @lc code=end

