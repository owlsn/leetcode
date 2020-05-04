// 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

// 示例：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
#include "mergeTwoLists.h"
#include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){
  ListNode* h = new ListNode(0);
  ListNode* head = h;
  while(l1 && l2){
    // std::cout << "l1:" << l1->val << ",l2:" << l2->val << std::endl;
    if(l1->val > l2->val){
      h->next = new ListNode(l2->val);
      l2 = l2->next;
    }
    else{
      h->next = new ListNode(l1->val);
      l1 = l1->next;
    }
    h = h->next;
  }
  h->next = l1 ? l1: l2;
  return head->next;
}