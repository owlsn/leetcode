// 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
// 必须原地修改，只允许使用额外常数空间。

// 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

//寻找到a[i-1] < a[i]的第一个i，然后将a[i-1]和后面第一个大于a[i-1]的数调换位置
//然后将a[i-1]后面的数逆序排列即可
//具体的原因是下一个排列的规律，在a[i-1] < a[i]的第一个i的时候，i-1后面的数都是有序排列的
//而将a[i-1]与a[j]调换位置之后，后面的数也都是有序排列的，但是按照大小来说，原排列的下一个排列，应该是a[i-1]换成下一个大于a[i-1]的数即a[j]
//而后面的排列是逆序的排列

#include "nextPermutation.h"
#include <iostream>
Solution::Solution() {}

Solution::~Solution() {}

void Solution::nextPermutation(std::vector<int>& nums){
  int pos = nums.size() - 1;
  while (pos > 0 && nums[pos] <= nums[pos - 1])
    pos--;
  std::reverse(nums.begin() + pos, nums.end());  //逆序
  if(pos > 0){
    auto iter = std::upper_bound(nums.begin() + pos, nums.end(), nums[pos - 1]);//使用upper_bound找到遍历过的数中第一个比num[pos-1]大的数
    std::swap(*iter, nums[pos - 1]);
  }
}