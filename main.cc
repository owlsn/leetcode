// gcc -Wall -std=c++11 -lstdc++ main.cc ./1.twoSum/twoSum.cc -o main
#include <iostream>

// #include "1.twoSum/twoSum.h"
// #include "2.addTwoNumbers/addTwoNumbers.h"
// #include "3.lengthOfLongestSubstring/lengthOfLongestSubstring.h"
// #include "4.findMedianSortedArrays/findMedianSortedArrays.h"
// #include "5.longestPalindrome/longestPalindrome.h"
// #include "6.zconvert/zconvert.h"
// #include "7.intreverse/intreverse.h"
// #include "8.myAtoi/myAtoi.h"
#include "9.isPalindrome/isPalindrome.h"

int main(int argc, char* argv[]) {
  auto solution = new Solution();

  // 1.twoSum
  // std::vector<int> nums = {3, 2, 3};
  // int target = 6;
  // std::vector<int> res;
  // res = solution->twoSum(nums, target);
  // for (auto it = res.begin(); it != res.end(); it++) {
  //   std::cout << *it << " ";
  // }

  // 2.addTwoNumbers
  // ListNode* l1 = new ListNode(2);
  // l1->next = new ListNode(4);
  // l1->next->next = new ListNode(3);
  // ListNode* l2 = new ListNode(5);
  // l2->next = new ListNode(6);
  // l2->next->next = new ListNode(4);
  // ListNode* res = solution->addTwoNumbers(l1, l2);
  // while(res != NULL){
  //   std::cout << res->val << " -> ";
  //   res = res->next;
  // }
  // std::cout << "NULL" << std::endl;

  // 3.lengthOfLongestSubstring
  // std::string s = "pwwkew";
  // int res = solution->lengthOfLongestSubstring(s);
  // std::cout << res << std::endl;

  // 4.findMedianSortedArrays
  // std::vector<int> nums1 = {};
  // std::vector<int> nums2 = {1};
  // double res = solution->findMedianSortedArrays(nums1, nums2);
  // std::cout<< res << std::endl;

  // 5.longestPalindrome
  // std::string s = "babad";
  // std::string res = solution->longestPalindrome(s);
  // std::cout << res << std::endl;

  // 6.zconvert
  // std::string str = "LEETCODEISHIRING";
  // int numRows = 4;
  // std::string res = solution->convert(str, numRows);
  // std::cout << res << std::endl;

  // 7.intreverse
  // int num = 1534236469;
  // int res = solution->reverse(num);
  // std::cout << res << std::endl;

  // 8.myAtoi
  // std::string str = "-2147483648";
  // int res = solution->myAtoi(str);
  // std::cout << res << std::endl;

  // 9.isPalindrome
  int x = 2147483647;
  bool res = solution->isPalindrome(x);
  std::cout << res << std::endl;
  
  return 0;
}