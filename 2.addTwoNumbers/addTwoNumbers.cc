// 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

// 示例：
// 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出：7 -> 0 -> 8
// 原因：342 + 465 = 807


// Definition for singly-linked list.
// public class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) { val = x; }
// }

 //使用循环，依次按位相加，使用新链表记录每一位的结果，使用add变量记录进位，循环的判断条件是l1->next==null || l2->next==null || add!=1
 //当其中一个链表加完之后，将另外一个链表剩下的部分依次添在后面
 //因此在相加的过程中就会有几种情况：
//1.l1!=null && l2!=null 
//2.l1==null && l2!=null
//3.l1!=null && l2==null
//4.l1==null && l2==null

#include "addTwoNumbers.h"
// #include <iostream>

Solution::Solution() {}

Solution::~Solution() {}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
  ListNode* res = new ListNode(-1);
  ListNode* head = res;
  int carry = 0;
  int sum = 0;
  while(l1 != NULL || l2 != NULL){
    if(l1 == NULL){
      sum = l2->val + carry;
      l2 = l2->next;
    }
    else if(l2 == NULL){
      sum = l1->val + carry;
      l1 = l1->next;
    }
    else{
      sum = l1->val + l2->val + carry;
      l1 = l1->next;
      l2 = l2->next;
    }

    if(sum >= 10){
      sum -= 10;
      carry = 1;
    }
    else{
      carry = 0;
    }
    // std::cout << sum << std::endl;
    res->next = new ListNode(sum);
    res = res->next;
  }
  if(carry != 0){
    res->next = new ListNode(carry);
    res = res->next;
  }
  return head->next;
}