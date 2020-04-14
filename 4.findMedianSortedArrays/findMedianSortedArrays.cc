// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
// 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
// 你可以假设 nums1 和 nums2 不会同时为空。

// 示例 1:
// nums1 = [1, 3]
// nums2 = [2]
// 则中位数是 2.0

// 示例 2:
// nums1 = [1, 2]
// nums2 = [3, 4]
// 则中位数是 (2 + 3)/2 = 2.5

//nums1和nums2有序
//若先将两个数组合并，则时间复杂度至少为O(m+n)
//采用二分查找的方式
//中位数的位置是将num1和num2划分为数字个数相等的两部分part1和part2，并且有max(part1) < min(part2)
//则根据这个等式条件可以由num1的一个位置i确定num2的一个位置j
//条件为：i + j = num1.length - i + num2.length - j ( + 1)
//相对应的num1和num2也会被分为两部分，假设为num1A，num1B和num2A，num2B，(都有可能为空)
//那么有max(num1A) < min(num2B)和max(num1B) < min(num2A)
//根据上述条件，则可以依次搜索符合要求的中位数
//首先根据划分为相等的两部分的要求，获得对应的划分
//然后根据是否满足划分条件判断是否为所要求的数
//搜索过程可以用二分法进行
//最终的结果如果numA.length + numB.length是奇数，那么，中位数就是max(part1)
//如果是偶数，则是(max(part1) + min(part2))/2

#include "findMedianSortedArrays.h"
// #include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2){
  if(nums1.size() > nums2.size()){
    return Solution::findMedianSortedArrays(nums2, nums1);
  }
  int m = nums1.size(), n = nums2.size();
  int lo = 0, hi = m * 2;
  int c1 = 0, c2 = 0;
  int la, lb, ra, rb;
  // std::cout << "m:" << m << ",n:" << n << ",lo:" << lo <<",hi:" << hi << "," << std::endl;
  while(lo <= hi){
    c1 = (lo + hi) / 2;
    c2 = m + n - c1;
    // std::cout << "c1:" << c1 << ",c2:" << c2 << std::endl;
    la = (c1 == 0)? INT_MIN : nums1[(c1 - 1) / 2];
    ra = (c1 == 2 * m)? INT_MAX : nums1[c1 / 2];
    lb = (c2 == 0)? INT_MIN : nums2[(c2 - 1) / 2];
    rb = (c2 == 2 * n) ? INT_MAX: nums2[c2 / 2];

    // std::cout << "la:" << la << ",ra:" << ra << ",lb:" << lb << ",rb:" << rb << std::endl;

    if(la > rb){
      hi = c1 - 1;
    }
    else if(ra < lb){
      lo = c1 + 1;
    }
    else{
      break;
    }
  }
  return (std::max(la, lb) + std::min(ra, rb)) / 2.0;
}