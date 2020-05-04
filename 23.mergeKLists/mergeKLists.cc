// 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

// 示例:
// 输入:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 输出: 1->1->2->3->4->4->5->6

// 使用归并排序对思想
// 将lists分为两部分，对两部分内部进行归并后，然后将两部分归并
#include "mergeKLists.h"

Solution::Solution() {}

Solution::~Solution() {}

ListNode* Solution::mergeKLists(std::vector<ListNode*>& lists){
  return merge(0, lists.size() - 1, lists);
}

ListNode* Solution::merge(int start, int end, std::vector<ListNode*>& lists){
  int mid = (start + end) / 2;
  if(start == end){
    return lists[start];
  }
  if(start > end){
    return nullptr;
  }
  return Solution::mergeTwoLists(merge(start, mid, lists), merge(mid + 1, end, lists));
}

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