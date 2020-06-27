/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.37%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 81.5K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
      if(num == 1){
        return true;
      }
      long left = 2, right = num, mid;
      long count = 0;
      while(left <= right){
        mid = left + (right - left) / 2;
        count = mid * mid;
        if(count > num){
          right = mid - 1;
        }
        else if(count < num){
          left = mid + 1;
        }
        else{
          return true;
        }
      }
      return false;
    }
};
// @lc code=end

