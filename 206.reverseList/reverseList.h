#include <stdio.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  Solution();
  ~Solution();
  ListNode* reverseList(ListNode* head);
};