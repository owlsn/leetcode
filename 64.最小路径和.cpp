/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (65.78%)
 * Likes:    498
 * Dislikes: 0
 * Total Accepted:    95.2K
 * Total Submissions: 144.6K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int count = 0;
      std::vector<std::vector<int> > dp(grid.size(), std::vector<int>(grid[0].size(), 0));
      dp[0][0] = grid[0][0];
      for(int i = 0; i < grid.size(); i ++){
        for(int j = 0; j < grid[i].size(); j ++){
          if(i == 0 && j > 0){
            dp[i][j] = grid[i][j] + dp[i][j - 1];
          }
          if(j == 0 && i > 0){
            dp[i][j] = grid[i][j] + dp[i - 1][j];
          }
        }
      }
      for(int i = 1; i < grid.size(); i ++){
        for(int j = 1; j < grid[i].size(); j ++){
          dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
      return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end

