// 给定一个可包含重复数字的序列，返回所有不重复的全排列。

// 示例:

// 输入: [1,1,2]
// 输出:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
#include "permuteUnique.h"


std::vector<std::vector<int> > Solution::permuteUnique(std::vector<int>& nums){
  std::vector<std::vector<int> > res;
  std::unordered_map<int, bool> used;
  std::sort(nums.begin(), nums.end());
  for(int i = 0; i < nums.size(); i ++){
    used.emplace(i, false);
  }
  std::vector<int> temp;
  backtrace(res, used, 0, nums, temp);
  return res;
}

void Solution::backtrace(std::vector<std::vector<int> >& res, std::unordered_map<int, bool>& used, int depth, std::vector<int>& nums, std::vector<int>& temp){
  if(depth == nums.size()){
    res.push_back(temp);
  }
  for(int i = 0; i < nums.size(); i ++){
    if(!used[i]){
      if(i > 0 && nums[i] == nums[i - 1] && used[i - 1]){
        break;
      }
      temp.push_back(nums[i]);
      used[i] = true;
      backtrace(res, used, depth + 1, nums, temp);
      temp.pop_back();
      used[i] = false;
    }
  }
}