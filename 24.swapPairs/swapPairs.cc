// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例:
// 给定 1->2->3->4, 你应该返回 2->1->4->3.

// 没什么特别的，两两进行交换就行了，因为题目要求不仅仅交换值，那就要记录pre，now和next的指针，交换他们

#include "swapPairs.h"

Solution::Solution() {}

Solution::~Solution() {}

ListNode* Solution::swapPairs(ListNode* head){
  ListNode* h = new ListNode(0);
  h->next = head;
  ListNode* first = h;
  ListNode* pre = h, * now = h, * next = h;
  while (h->next && h->next->next)
  {
    pre = h;
    h = h->next;
    now = h;
    next = h->next;
    
    // swap
    pre->next = next;
    now->next = next->next;
    pre->next->next = now;
  }
  
  return first->next;
}