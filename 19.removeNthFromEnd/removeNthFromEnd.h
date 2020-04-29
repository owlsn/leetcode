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
  ListNode* removeNthFromEnd(ListNode* head, int n);
};