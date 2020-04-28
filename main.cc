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
// #include "9.isPalindrome/isPalindrome.h"
// #include "10.isMatch/isMatch.h"
// #include "11.maxArea/maxArea.h"
// #include "12.intToRoman/intToRoman.h"
// #include "13.romanToInt/romanToInt.h"
// #include "14.longestCommonPrefix/longestCommonPrefix.h"
// #include "15.threeSum/threeSum.h"
// #include "16.threeSumClosest/threeSumClosest.h"
// #include "17.letterCombinations/letterCombinations.h"
#include "18.fourSum/fourSum.h"

int main(int argc, char* argv[]) {
  auto solution = new Solution();

  // 1.twoSums
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
  // int x = 2147483647;
  // bool res = solution->isPalindrome(x);
  // std::cout << res << std::endl;

  // 10.isMatch
  // std::string s = "aa";
  // std::string p = "a*";
  // bool res = solution->isMatch(s, p);
  // std::cout << res << std::endl;

  // 11.maxArea
  // std::vector<int> height{1,8,6,2,5,4,8,3,7};
  // int res = solution->maxArea(height);
  // std::cout << res << std::endl;
  
  // 12.intToRoman
  // int num = 1234;
  // std::string res = solution->intToRoman(num);
  // std::cout << res << std::endl;

  // 13.romanToInt
  // std::string str = "MCCXXXIV";
  // int res = solution->romanToInt(str);
  // std::cout << res << std::endl;

  // 14.longestCommonPrefix
  // std::vesctor<std::string> strs{"flower","flow","flight"};
  // std::string res = solution->longestCommonPrefix(strs);
  // std::cout << res << std::endl;

  // 15.threeSum
  // std::vector<int> nums{-1, 0, 1, 2, -1, -4};
  // std::vector<int> nums{0, 0, 0};
  // auto res = solution->threeSum(nums);
  // for(int i = 0; i < res.size(); i ++){
  //   for(int j = 0; j < res[i].size(); j ++){
  //     std::cout << res[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }
  
  // 16.threeSumClosest
  // std::vector<int> nums{-1,2,1,-4};
  // int target = 1;
  // auto res = solution->threeSumClosest(nums, target);
  // std::cout << res << std::endl;

  // 17.letterCombinations
  // std::string digits = "23";
  // std::vector<std::string> res = solution->letterCombinations(digits);
  // for(auto value : res){
  //   std::cout << value << " ";
  // }

  // 18.fourSum
  std::vector<int> nums{1,-2,-5,-4,-3,3,3,5};
  int target = -11;
  auto res = solution->fourSum(nums, target);
  for(int i = 0; i < res.size(); i ++){
    for(int j = 0; j < res[i].size(); j ++){
      std::cout << res[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}