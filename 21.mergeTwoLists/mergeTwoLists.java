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

 // 基础题目
public class mergeTwoLists {

    public static void main(String[] args){
        mergeTwoLists test = new mergeTwoLists();
        ListNode l1 = new ListNode(1);
        ListNode l1_head = l1;
        l1.next = new ListNode(3);
        l1 = l1.next;

        ListNode l2 = new ListNode(1);
        ListNode l2_head = l2;
        l2.next = new ListNode(4);
        l2 = l2.next;
        ListNode list = test.mergeTwoLists(l1_head, l2_head);
        while(list != null){
            System.out.println(list.val);
            list = list.next;
        }
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode list = new ListNode(0);
        ListNode head = list;
        int temp = 0;
        while(l1 != null || l2 != null){
            if(l1 == null){
                while(l2 != null){
                    head.next = new ListNode(l2.val);
                    head = head.next;
                    l2 = l2.next;
                }
            }
            else if(l2 == null){
                while(l1 != null){
                    head.next = new ListNode(l1.val);
                    head = head.next;
                    l1 = l1.next;
                }
            }
            else{
                if(l1.val > l2.val){
                    temp = l2.val;
                    l2 = l2.next;
                }
                else{
                    temp = l1.val;
                    l1 = l1.next;
                }
                head.next = new ListNode(temp);
                head = head.next;
            }
        }
        return list.next;
    }
}