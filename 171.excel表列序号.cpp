/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (67.40%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    42.3K
 * Total Submissions: 62.7K
 * Testcase Example:  '"A"'
 *
 * 给定一个Excel表格中的列名称，返回其相应的列序号。
 * 
 * 例如，
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: "A"
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: "AB"
 * 输出: 28
 * 
 * 
 * 示例 3:
 * 
 * 输入: "ZY"
 * 输出: 701
 * 
 * 致谢：
 * 特别感谢 @ts 添加此问题并创建所有测试用例。
 * 
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
      if(s.empty()){
        return 0;
      }
      std::unordered_map<char, int> map{
        {'A' , 1},
        {'B' , 2},
        {'C' , 3},
        {'D' , 4},
        {'E' , 5},
        {'F' , 6},
        {'G' , 7},
        {'H' , 8},
        {'I' , 9},
        {'J' , 10},
        {'K' , 11},
        {'L' , 12},
        {'M' , 13},
        {'N' , 14},
        {'O' , 15},
        {'P' , 16},
        {'Q' , 17},
        {'R' , 18},
        {'S' , 19},
        {'T' , 20},
        {'U' , 21},
        {'V' , 22},
        {'W' , 23},
        {'X' , 24},
        {'Y' , 25},
        {'Z' , 26},
      };
      int ans = 0, len = s.length();
      for(int i = 0; i < len; i ++){
        ans += pow(26, len - i - 1) * map[s[i]];
      }
      return ans;
    }
};
// @lc code=end

