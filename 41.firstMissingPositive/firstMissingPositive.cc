// 给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

// 示例 1:
// 输入: [1,2,0]
// 输出: 3

// 示例 2:
// 输入: [3,4,-1,1]
// 输出: 2

// 示例 3:
// 输入: [7,8,9,11,12]
// 输出: 1

// 说明:
// 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

//将数字的下标作为索引键，将值的符号作为是否存在的标识，负号表示存在，正号表示不存在
#include "firstMissingPositive.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

int Solution::firstMissingPositive(std::vector<int>& nums){
  bool flag = false;
  int len = nums.size();
  for(int i = 0; i < len; ++ i){
    if(nums[i] == 1){
      flag = true;
    }
    if(nums[i] <= 0){
      nums[i] = 1;
    }
  }
  if(!flag){
    return 1;
  }
  if(nums.size() == 1){
    return 2;
  }
  // for(int& i : nums){
  //   std::cout << i << " ";
  // }
  // std::cout << std::endl;
  int temp;
  for(int i = 0; i < len; i ++){
    temp = abs(nums[i]);
    if(temp == len && nums[0] > 0){
      nums[0] = - nums[0];
    }
    if(temp < len && nums[temp] > 0){
      nums[temp] = - nums[temp];
    }
  }
  for(int& i : nums){
    if(abs(i) < len && nums[abs(i)] > 0){
      if(i == len){
        nums[0] = - nums[abs(i)];
      }
      else{
        nums[abs(i)] = - nums[abs(i)];
      }
    }
  }
  // for(int& i : nums){
  //   std::cout << i << " ";
  // }
  // std::cout << std::endl;
  for(int i = 1; i < len; i ++){
    if(nums[i] > 0){
      return i;
    }
  }
  if(nums[0] > 0){
    return len;
  }
  return len + 1;
}