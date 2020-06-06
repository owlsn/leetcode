// 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

// 示例:

// 输入: [1,2,3]
// 输出:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

#include "permute.h"

std::vector<std::vector<int> > Solution::permute(std::vector<int>& nums){
  std::vector<std::vector<int> > res;
  std::unordered_map<int, bool> used;
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
      temp.push_back(nums[i]);
      used[i] = true;
      backtrace(res, used, depth + 1, nums, temp);
      temp.pop_back();
      used[i] = false;
    }
  }
}

