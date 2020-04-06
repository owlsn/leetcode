// gcc -Wall -std=c++11 -lstdc++ main.cc ./1.twoSum.cc -o main
#include <iostream>
#include "1.twoSum/twoSum.h"
#include <vector>

int main(int argc, char* argv[]){
  auto solution = new Solution();
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> res;
  res = solution->twoSum(nums, target);
  for(auto it = res.begin(); it != res.end(); it ++){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "main" << std::endl;
  return 0;
}