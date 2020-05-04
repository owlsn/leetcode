// 反转一个单链表。

// 示例:

// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
// 进阶:
// 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

#include "reverseList.h"

Solution::Solution() {}

Solution::~Solution() {}

ListNode* Solution::reverseList(ListNode* head){
  ListNode* now = nullptr, * pre = head, * next = nullptr;
  while(pre){
    next = pre->next;
    pre->next = now;
    now = pre;
    pre = next;
  }
  return now;
}