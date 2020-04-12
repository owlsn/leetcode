// gcc -Wall -std=c++11 -lstdc++ main.cc ./1.twoSum/twoSum.cc -o main
#include <iostream>
// #include <vector>

// #include "1.twoSum/twoSum.h"
// #include "2.addTwoNumbers/addTwoNumbers.h"
#include "3.lengthOfLongestSubstring/lengthOfLongestSubstring.h"

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
  std::string s = "pwwkew";
  int res = solution->lengthOfLongestSubstring(s);
  std::cout << res << std::endl;
  
  return 0;
}