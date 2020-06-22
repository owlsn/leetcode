/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.82%)
 * Likes:    380
 * Dislikes: 0
 * Total Accepted:    89.9K
 * Total Submissions: 170.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
 * 
 * 输入为 非空 字符串且只包含数字 1 和 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个字符串仅由字符 '0' 或 '1' 组成。
 * 1 <= a.length, b.length <= 10^4
 * 字符串如果不是 "0" ，就都不含前导零。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
      int a_len = a.length() - 1, b_len = b.length() - 1;
      int ans = 0, temp;
      std::string res;
      while(a_len >= 0 && b_len >= 0){
        temp = (a[a_len] - '0') + (b[b_len] - '0') + ans;
        res.insert(res.begin(), '0' + (temp % 2));
        ans = temp / 2;
        a_len --;
        b_len --;
      }
      while(a_len >= 0){
        temp = (a[a_len] - '0') + ans;
        res.insert(res.begin(), '0' + (temp % 2));
        ans = temp / 2;
        a_len --;
      }
      while(b_len >= 0){
        temp = (b[b_len] - '0') + ans;
        res.insert(res.begin(), '0' + (temp % 2));
        ans = temp / 2;
        b_len --;
      }
      if(ans != 0){
        res.insert(res.begin(), '0' + ans);
      }
      return res;
    }
};
// @lc code=end

