/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 *
 * https://leetcode-cn.com/problems/third-maximum-number/description/
 *
 * algorithms
 * Easy (35.02%)
 * Likes:    133
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 79.4K
 * Testcase Example:  '[3,2,1]'
 *
 * 给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3, 2, 1]
 * 
 * 输出: 1
 * 
 * 解释: 第三大的数是 1.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1, 2]
 * 
 * 输出: 2
 * 
 * 解释: 第三大的数不存在, 所以返回最大的数 2 .
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: [2, 2, 3, 1]
 * 
 * 输出: 1
 * 
 * 解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
 * 存在两个值为2的数，它们都排第二。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
      std::unordered_map<int, bool> exist;
      int j = 0;
      for(int i = 0; i < nums.size(); i ++){
        if(exist.find(nums[i]) == exist.end()){
          nums[j ++] = nums[i];
          exist.insert({nums[i], true});
        }
      }
      int k = 3, count = 0;
      if(j < k){
        for(int i = 0; i < j; i ++){
          count = max(count, nums[i]);
        }
      }
      else{
        count =  third(nums, 0, j - 1, j - k);
      }
      return count;
    }

    int third(vector<int>& nums, int start, int end, int k){
      int i = partion(nums, start, end);
      if (i == k){
        return nums[i];
      }
      if(i > k){
        return third(nums, start, i - 1, k);
      }
      else{
        return third(nums, i + 1, end, k);
      }
    }

    int partion(vector<int>& nums, int start, int end){
      int index = nums[start];
      while(start < end){
        while(start < end && nums[end] >= index){
          end --;
        }
        nums[start] = nums[end];
        while(start < end && nums[start] <= index){
          start ++;
        }
        nums[end] = nums[start];
      }
      nums[start] = index;
      return start;
    }
};
// @lc code=end

