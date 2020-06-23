/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (45.66%)
 * Likes:    398
 * Dislikes: 0
 * Total Accepted:    84.2K
 * Total Submissions: 184.3K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* current = new ListNode(-1);
      current->next = head;
      ListNode* dummy = current;
      while (current != nullptr && current->next != nullptr)
      {
        if(current->next->val == val){
          current->next = current->next->next;
        }
        else{
          current = current->next;
        }
      }
      return dummy->next;
    }
};
// @lc code=end

