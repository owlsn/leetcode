#include <stdio.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
 private:
 public:
  Solution();
  ~Solution();
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};