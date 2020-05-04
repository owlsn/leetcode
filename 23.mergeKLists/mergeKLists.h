#include <stdio.h>
#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  Solution();
  ~Solution();
  ListNode* mergeKLists(std::vector<ListNode*>& lists);
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
  ListNode* merge(int start, int end, std::vector<ListNode*>& lists);
};