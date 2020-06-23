/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (37.89%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    28.2K
 * Total Submissions: 74.4K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
      int counter = 0;
      string str;
      while(n > 0){
        if(n % 26 == 0){
          str = 'Z' + str;
          n /= 26;
          n --;
        }
        else{
          str = (char)('A' + n % 26 - 1) + str;
          n /= 26;
        }
      }
      return str;
    }
};
// @lc code=end

