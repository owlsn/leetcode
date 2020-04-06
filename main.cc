// gcc -Wall -std=c++11 -lstdc++ main.cc ./1.twoSum.cc -o main
#include <iostream>
#include <vector>

#include "1.twoSum/twoSum.h"

int main(int argc, char* argv[]) {
  auto solution = new Solution();
  std::vector<int> nums = {3, 2, 3};
  int target = 6;
  std::vector<int> res;
  res = solution->twoSum(nums, target);
  for (auto it = res.begin(); it != res.end(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  std::cout << "main" << std::endl;
  return 0;
}