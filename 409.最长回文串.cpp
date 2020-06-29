/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (55.05%)
 * Likes:    195
 * Dislikes: 0
 * Total Accepted:    51.8K
 * Total Submissions: 94K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
      std::unordered_map<char, int> smap;
      for(int i = 0; i < s.length(); i ++){
        auto iter = smap.find(s[i]);
        if(iter == smap.end()){
          smap.insert({s[i], 1});
        }
        else{
          iter->second ++;
        }
      }
      int count = 0;
      for(auto it = smap.begin(); it != smap.end(); it ++){
        if(it->second % 2 == 1){
          count ++;
        }
      }
      return count == 0 ? s.length() :s.length() - count + 1;
    }
};
// @lc code=end

