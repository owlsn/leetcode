/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (37.92%)
 * Likes:    617
 * Dislikes: 0
 * Total Accepted:    59.3K
 * Total Submissions: 155.8K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
      std::unordered_map<char, int> mp;
      for(int i = 0; i < t.length(); i ++){
        auto iter = mp.find(t[i]);
        if(iter == mp.end()){
          mp.insert({t[i], 1});
        }
        else{
          iter->second ++;
        }
      }
      
    }
};
// @lc code=end

