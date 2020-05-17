// 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。

// 说明：
// 所有数字（包括 target）都是正整数。
// 解集不能包含重复的组合。 

// 示例 1:
// 输入: candidates = [2,3,6,7], target = 7,
// 所求解集为:
// [
//   [7],
//   [2,2,3]
// ]

// 示例 2:
// 输入: candidates = [2,3,5], target = 8,
// 所求解集为:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

//采用回溯法，依次用target减去所有的数，并且下次减的数不能比此次小
//如果target减到0说明符合要求，将存在stack中的数存入结果列表
//如果target<0则需要回溯
#include "combinationSum.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

std::vector<std::vector<int> > Solution::combinationSum(std::vector<int>& candidates, int target){
  std::vector<std::vector<int> > ret;
  std::vector<int> l;
  std::sort(candidates.begin(), candidates.end());
  backtrace(candidates, 0, target, ret, l);
  return ret;
}

void Solution::backtrace(std::vector<int>& candidates, int start, int target, std::vector<std::vector<int> >& ret, std::vector<int>& l){
  // std::cout << target << std::endl;
  if(target == 0){
    ret.push_back(l);
    return;
  }
  for(int i = start; i < candidates.size(); i ++){
    if(candidates[i] > target){
      continue;
    }
    l.push_back(candidates[i]);
    backtrace(candidates, i, target - candidates[i], ret, l);
    l.pop_back();
  }
}