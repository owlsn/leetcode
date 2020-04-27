// 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

// 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
// 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

// 和上题差不多，先对数组排序，然后确定一个基准元素后用双指针法
// 当最后判断结果的时候，如果和大于最小的值就可以直接跳过了

#include "threeSumClosest.h"

Solution::Solution() {}

Solution::~Solution() {}

int Solution::threeSumClosest(std::vector<int>& nums, int target){
  std::sort(nums.begin(), nums.end());
  if(nums.size() < 3){
    return -1;
  }
  int result = nums[0] + nums[1] + nums[2], ans;
  int len = nums.size(), left, right;
  for(int i = 0; i < nums.size() - 2; i ++){
    if(i > 0 && nums[i] == nums[i - 1]){
      continue;
    }
    left = i + 1;
    right = len - 1;
    while(left < right){
      ans = nums[i] + nums[left] + nums[right];
      if(abs(ans - target) < abs(result - target)){
        result = ans;
      }
      if(ans == target){
        return target;
      }
      else if(ans < target){
        left ++;
      }
      else{
        right --;
      }
    }
  }
  return result;
}