// 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
// k 是一个正整数，它的值小于或等于链表的长度。
// 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 示例 :
// 给定这个链表：1->2->3->4->5
// 当 k = 2 时，应当返回: 2->1->4->3->5
// 当 k = 3 时，应当返回: 3->2->1->4->5

// 说明 :
// 你的算法只能使用常数的额外空间。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 采用O(1)空间的方式，就是只对指针进行操作
// 所以每k个元素取下来，然后将之反转，然后接在原始的位置，而这个操作不用开辟另外的空间，只需要将元素之间的指针进行变换
// 改写翻转链表的方法
#include "reverseKGroup.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

ListNode* Solution::reverseKGroup(ListNode* head, int k){
  ListNode* h = new ListNode(0);
  h->next = head;
  ListNode* first = h, * pre = h, * now = head, * temp = nullptr;
  int i = 0;
  while (now)
  {
    for(i = 0; i < k && now; i ++){
      now = now->next;
    }
    if(i != k){
      break;
    }
    temp = pre->next;
    // std::cout << "now:" << now->val << std::endl;
    pre->next = Solution::reverseList(temp, now);
    pre = temp;
  }
  return first->next;
}

ListNode* Solution::reverseList(ListNode* head, ListNode* tail){
  ListNode* now = tail, * pre = head, * next = nullptr;
  while(pre != tail){
    next = pre->next;
    pre->next = now;
    now = pre;
    pre = next;
  }
  return now;
}