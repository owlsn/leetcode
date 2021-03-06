/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (61.21%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    56.3K
 * Total Submissions: 92K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
      std::vector<int> row(rowIndex + 1, 0);
      for(int i = 0; i < rowIndex + 1; i ++){
        row[i] = 1;
        if (i > 1) {
          for(int j = i - 1; j > 0; j --){
            row[j] = row[j] + row[j - 1];
          }
        }
      }
      return row;
    }
};
// @lc code=end

