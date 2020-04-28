// 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
// 判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

// 注意：
// 答案中不可以包含重复的四元组。

// 示例：
// 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
// 满足要求的四元组集合为：
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]


// 和之前的三数之和类似
// 先将数组排序，取基准元素后，调用三数之和算法，然后将得到的结果合并
#include "fourSum.h"

Solution::Solution() {}

Solution::~Solution() {}

std::vector<std::vector<int> > Solution::fourSum(std::vector<int>& nums, int target){
  std::vector<std::vector<int> > ret;
  int len = nums.size();
  if(len < 4){
    return ret;
  }
  std::sort(nums.begin(), nums.end());
  int first, second, third, fourth, ans;
  for(int i = 0; i < len - 3; i ++){
    first = i;
    if( i > 0 && nums[i] == nums[i - 1]){
      continue;
    }
    for(int j = i + 1; j < len - 2; j ++){
      second = j;
      if(j > i + 1 && nums[j] == nums[j - 1]){
        continue;
      }
      third = j + 1;
      fourth = len - 1;
      while(third < fourth){
        ans = nums[first] + nums[second] + nums[third] + nums[fourth];
        if(ans == target){
          ret.push_back({nums[first], nums[second], nums[third], nums[fourth]});
          while(third < fourth && nums[third] == nums[third + 1]){
            third ++;
          }
          while(third < fourth && nums[fourth] == nums[fourth - 1]){
            fourth --;
          }
          third ++;
          fourth --;
        }
        else if(ans > target){
          fourth --;
        }
        else{
          third ++;
        }
      }
    }
  }
  return ret;
}