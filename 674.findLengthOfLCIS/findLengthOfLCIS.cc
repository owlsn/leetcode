
// 给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

//  

// 示例 1:

// 输入: [1,3,5,4,7]
// 输出: 3
// 解释: 最长连续递增序列是 [1,3,5], 长度为3。
// 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
// 示例 2:

// 输入: [2,2,2,2,2]
// 输出: 1
// 解释: 最长连续递增序列是 [2], 长度为1。

// 直接遍历，nums[i] < nums[i + 1]

#include "findLengthOfLCIS.h"

int Solution::findLengthOfLCIS(std::vector<int>& nums){
  int left = 0, count = 0;
  for (int i = 0; i < nums.size(); i ++) {
    if(i > 0 && nums[i] <= nums[i - 1]){
      left = i;
    }
    count = std::max(count, i - left + 1);
  }
  return count;
}