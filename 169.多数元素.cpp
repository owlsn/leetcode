/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (63.57%)
 * Likes:    632
 * Dislikes: 0
 * Total Accepted:    178.8K
 * Total Submissions: 281.2K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int count = 0, ans = nums[0];
      for(int i = 0; i < nums.size(); i ++){
        if(nums[i] == ans){
          count ++;
        }
        else{
          count --;
        }
        if(count == 0){
          count = 1;
          ans = nums[i];
        }
      }
      return ans;
    }
};
// @lc code=end

