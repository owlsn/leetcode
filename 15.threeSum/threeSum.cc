// 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

// 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
// 满足要求的三元组集合为：
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// 先排序，然后用双指针法
// 基准元素选择左边的元素，一开始选择中间元素为基准元素，则判断重复元素的时候会出现问题

#include "threeSum.h"

Solution::Solution() {}

Solution::~Solution() {}

std::vector<std::vector<int> > Solution::threeSum(std::vector<int>& nums){
  std::vector<std::vector<int> > ret;
  if(nums.size() < 3){
    return ret;
  }
  std::sort(nums.begin(), nums.end());
  int len = nums.size(), left, right;
  for(int i = 0; i < nums.size() - 2; i ++){
    if(nums[i] > 0){
      break;
    }
    if(i > 0 && nums[i] == nums[i - 1]){
      continue;
    }
    left = i + 1;
    right = len - 1;
    while(left < right){
      if(nums[i] + nums[left] + nums[right] == 0){
        ret.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
        while(left < right && nums[left] == nums[left + 1]){
          left ++;
        }
        while(left < right && nums[right] == nums[right - 1]){
          right --;
        }
        left ++;
        right --;
      }
      else if(nums[i] + nums[left] + nums[right] < 0){
        left ++;
      }
      else{
        right --;
      }
    }
  }
  return ret;
}