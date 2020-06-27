/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (42.17%)
 * Likes:    530
 * Dislikes: 0
 * Total Accepted:    97.8K
 * Total Submissions: 231.8K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      int len = 0;
      ListNode* h = head;
      while (h != nullptr)
      {
        len ++;
        h = h->next;
      }
      int mid = len / 2;
      ListNode* start = head;
      while(mid > 0 && start != nullptr){
        start = start->next;
        mid --;
      }
      ListNode* n = reverseList(start);
      while (n != nullptr && head != nullptr) {
        if(n->val == head->val){
          n = n->next;
          head = head->next;
        }
        else{
          return false;
        }
      }
      return true;
    }

    ListNode* reverseList(ListNode* head) {
      ListNode* next = nullptr, *pre = nullptr, *h = head;
      while (h != nullptr)
      {
        next = h->next;
        h->next = pre;
        pre = h;
        h = next;
      }
      return pre;
    }
};
// @lc code=end

