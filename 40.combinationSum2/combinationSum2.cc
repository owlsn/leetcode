// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用一次。

// 说明：
// 所有数字（包括目标数）都是正整数。
// 解集不能包含重复的组合。 

// 示例 1:
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 所求解集为:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]

// 示例 2:
// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:
// [
//   [1,2,2],
//   [5]
// ]

//和上一道题同理，不过这里数字是能使用一次
//数字只能是有一次的判断方式,当i何pre相等的时候就跳过
#include "combinationSum2.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

std::vector<std::vector<int> > Solution::combinationSum2(std::vector<int>& candidates, int target){
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
    if(candidates[i] > target || (i > start && candidates[i] == candidates[i - 1])){
      continue;
    }
    l.push_back(candidates[i]);
    backtrace(candidates, i + 1, target - candidates[i], ret, l);
    l.pop_back();
  }
}