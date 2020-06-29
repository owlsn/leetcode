/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (62.72%)
 * Likes:    520
 * Dislikes: 0
 * Total Accepted:    132K
 * Total Submissions: 210.3K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      return findKth(nums, 0, nums.size() - 1, nums.size() - k);
    }

    int findKth(vector<int>& nums, int start, int end, int k){
      int index = quickSort(nums, start, end);
      // std::cout << index << std::endl;
      if(index == k){
        return nums[index];
      }
      if(index < k){
        return findKth(nums, index + 1, end, k);
      }
      else{
        return findKth(nums, start, index - 1, k);
      }
    }

    int quickSort(vector<int>& nums, int start, int end){
      int index = nums[start];
      while (start < end) {
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

