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
// #include "18.fourSum/fourSum.h"
// #include "19.removeNthFromEnd/removeNthFromEnd.h"
// #include "20.isValid/isValid.h"
// #include "21.mergeTwoLists/mergeTwoLists.h"
// #include "22.generateParenthesis/generateParenthesis.h"
// #include "23.mergeKLists/mergeKLists.h"
// #include "24.swapPairs/swapPairs.h"
// #include "25.reverseKGroup/reverseKGroup.h"
// #include "26.removeDuplicates/removeDuplicates.h"
// #include "27.removeElement/removeElement.h"
// #include "28.strStr/strStr.h"
// #include "29.divide/divide.h"
// #include "30.findSubstring/findSubstring.h"
// #include "31.nextPermutation/nextPermutation.h"
// #include "32.longestValidParentheses/longestValidParentheses.h"
// #include "33.search/search.h"
// #include "34.searchRange/searchRange.h"
// #include "35.searchInsert/searchInsert.h"
// #include "36.isValidSudoku/isValidSudoku.h"
// #include "37.solveSudoku/solveSudoku.h"
#include "39.combinationSum/combinationSum.h"

// #include "206.reverseList/reverseList.h"

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
  // std::vector<int> nums{1,-2,-5,-4,-3,3,3,5};
  // int target = -11;
  // auto res = solution->fourSum(nums, target);
  // for(int i = 0; i < res.size(); i ++){
  //   for(int j = 0; j < res[i].size(); j ++){
  //     std::cout << res[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  // 19.removeNthFromEnd
  // ListNode* head = new ListNode(1);
  // head->next = new ListNode(2);
  // head->next->next = new ListNode(3);
  // ListNode* ret = solution->removeNthFromEnd(head, 1);
  // while (ret)
  // {
  //   std::cout << ret->val << " ";
  //   ret = ret->next;
  // }

  // 20.isValid
  // std::string str = "()[]{}";
  // bool res = solution->isValid(str);
  // std::cout << res << std::endl;

  // 21.mergeTwoLists
  // ListNode* l1 = new ListNode(2);
  // l1->next = new ListNode(3);
  // l1->next->next = new ListNode(4);
  // ListNode* l2 = new ListNode(2);
  // l2->next = new ListNode(5);
  // l2->next->next = new ListNode(6);
  // ListNode* res = solution->mergeTwoLists(l1, l2);
  // while(res){
  //   std::cout << res->val << " ";
  //   res = res->next;
  // }

  // 22.generateParenthesis
  // int num = 3;
  // auto res = solution->generateParenthesis(num);
  // for(auto str : res){
  //   std::cout << str << std::endl;
  // }

  // 23.mergeKLists
  // ListNode* l1 = new ListNode(2);
  // l1->next = new ListNode(3);
  // l1->next->next = new ListNode(4);
  // ListNode* l2 = new ListNode(2);
  // l2->next = new ListNode(5);
  // l2->next->next = new ListNode(6);
  // ListNode* l3 = new ListNode(2);
  // l3->next = new ListNode(3);
  // l3->next->next = new ListNode(4);
  // std::vector<ListNode* > lists;
  // lists.push_back(l1);
  // lists.push_back(l2);
  // lists.push_back(l3);
  // ListNode* res = solution->mergeKLists(lists);
  // while(res){
  //   std::cout << res->val << " ";
  //   res = res->next;
  // }

  // 24.swapPairs
  // ListNode* l1 = new ListNode(2);
  // l1->next = new ListNode(3);
  // l1->next->next = new ListNode(4);
  // auto res = solution->swapPairs(l1);
  // while(res){
  //   std::cout << res->val << " ";
  //   res = res->next;
  // }

  // 25.reverseKGroup
  // ListNode* l1 = new ListNode(1);
  // ListNode* head = l1;
  // l1->next = new ListNode(2);
  // l1 = l1->next;
  // l1->next = new ListNode(3);
  // l1 = l1->next;
  // l1->next = new ListNode(4);
  // l1 = l1->next;
  // l1->next = new ListNode(5);
  // l1 = l1->next;
  // int k = 2;
  // auto res = solution->reverseKGroup(head, k);
  // while(res){
  //   std::cout << res->val << " ";
  //   res = res->next;
  // }

  // 26.removeDuplicates
  // std::vector<int> nums{1, 2, 2, 3, 4, 5};
  // auto res = solution->removeDuplicates(nums);
  // std::cout << res << std::endl;

  // 27.removeElement
  // std::vector<int> nums{1, 2, 2, 3, 4, 5};
  // int k = 2;
  // auto res = solution->removeElement(nums, k);
  // std::cout << res << std::endl;

  // 28.strStr
  // std::string haystack = "BBC ABCDAB ABCDABCDABDE", needle = "ABCDABD";
  // auto res = solution->strStr(haystack, needle);
  // std::cout << res << std::endl;

  // 29.divide
  // int dividend = 10, divisor = -3;
  // auto res = solution->divide(dividend, divisor);
  // std::cout << res << std::endl;

  // 30.findSubstring
  // std::string s = "barfoofoobarthefoobarman";
  // std::vector<std::string> words{"bar","foo","the"};
  // auto res = solution->findSubstring(s, words);
  // for(auto value : res){
  //   std::cout << value << " ";
  // }

  // 31.nextPermutation
  // std::vector<int> nums{1,2};
  // solution->nextPermutation(nums);
  // for(int value : nums){
  //   std::cout << value <<  " ";
  // }

  // 32.longestValidParentheses
  // std::string str = "()()()()()(())";
  // auto res = solution->longestValidParentheses(str);
  // std::cout << res << std::endl;

  // 33.search
  // std::vector<int> nums{4,5,6,0,1,2,3};
  // int target = 1;
  // auto res = solution->search(nums, target);
  // std::cout << res << std::endl;

  // 34.searchRange
  // std::vector<int> nums{1};
  // int target = 0;
  // auto res = solution->searchRange(nums, target);
  // std::cout << res[0] << "," << res[1] << std::endl;

  // 35.searchInsert
  // std::vector<int> nums{1,2,3,5,6,7};
  // int target = 4;
  // auto res = solution->searchInsert(nums, target);
  // std::cout << res << std::endl;

  // 36.isValidSudoku
  // std::vector<std::vector<char> > board{
  //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
  //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
  //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
  //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
  //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
  //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
  //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
  //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
  //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  // bool res = solution->isValidSudoku(board);
  // std::cout << res << std::endl;

  // 37.solveSudoku
  // std::vector<std::vector<char> > board{
  //     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
  //     {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
  //     {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
  //     {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
  //     {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
  //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
  //     {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
  //     {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
  //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  // solution->solveSudoku(board);
  // for(int i = 0; i < board.size(); i ++){
  //   for(int j = 0; j < board[i].size(); j ++){
  //     std::cout << board[i][j] << " ";
  //   }
  //   std::cout << std::endl;
  // }

  // 39.combinationSum
  std::vector<int> candidates{2,3,6,7};
  int target = 7;
  auto res = solution->combinationSum(candidates, target);
  for(auto& vec : res){
    for(int v : vec){
      std::cout << v << " ";
    }
    std::cout << std::endl;
  }

  // 206.reverseList
  // ListNode* l1 = new ListNode(2);
  // l1->next = new ListNode(3);
  // l1->next->next = new ListNode(4);
  // auto res = solution->reverseList(l1);
  // while(res){
  //   std::cout << res->val << " ";
  //   res = res->next;
  // }

  return 0;
}