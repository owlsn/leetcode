// 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

// 你的算法时间复杂度必须是 O(log n) 级别。
// 如果数组中不存在目标值，返回 [-1, -1]。

// 示例 1:
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: [3,4]

// 示例 2:
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: [-1,-1]

//二分查找
//找到目标元素后，分别在左右区间继续找,直到找不到为止，最后一次记录的位置就分别为左边界和右边界

#include "searchRange.h"

Solution::Solution() {}

Solution::~Solution() {}

std::vector<int> Solution::searchRange(std::vector<int>& nums, int target){
  int len = nums.size();
  std::vector<int> ret{-1, -1};
  if(!len){
    return ret;
  }
  int low = 0, high = len - 1;
  int mid;
  // 寻找右边界的二分查找
  while(low <= high){
    mid = (low + high) / 2;
    if(nums[mid] <= target){
      low = mid + 1;
    }
    if(nums[mid] > target){
      high = mid - 1;
    }
  }
  if(high < 0 || nums[high] != target){
    ret[1] = -1;
  }
  else{
    ret[1] = high;
  }
  low = 0, high = len - 1;
  // 寻找左边界的二分查找
  while(low <= high){
    mid = (low + high) / 2;
    if(nums[mid] < target){
      low = mid + 1;
    }
    if(nums[mid] >= target){
      high = mid - 1;
    }
  }
  if(low >= len || nums[low] != target){
    ret[0] = -1;
  }
  else{
    ret[0] = low;
  }

  return ret;
}

