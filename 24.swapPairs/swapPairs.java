// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
// 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例:
// 给定 1->2->3->4, 你应该返回 2->1->4->3.

// 没什么特别的，两两进行交换就行了，因为题目要求不仅仅交换值，那就要记录pre，now和next的指针，交换他们

public class swapPairs {

    public static void main(String[] args){
        swapPairs test = new swapPairs();
        ListNode l1 = new ListNode(1);
        ListNode l1_head = l1;
        l1.next = new ListNode(4);
        l1 = l1.next;
        l1.next = new ListNode(5);
        l1 = l1.next;
        l1.next = new ListNode(6);
        l1 = l1.next;
        l1.next = new ListNode(2);
        l1 = l1.next;
        l1.next = new ListNode(3);
        l1 = l1.next;
        l1.next = new ListNode(8);
        l1 = l1.next;
        l1.next = new ListNode(9);
        l1 = l1.next;
        l1.next = new ListNode(10);

        ListNode result = test.swapPairs(l1_head);
        while(result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }

    public ListNode swapPairs(ListNode head) {
        ListNode list = new ListNode(0);
        list.next = head;
        ListNode pre = null, now = null, next = null, temp = list;
        while(temp != null){
            pre = temp;
            // System.out.println("pre:" + pre.val);
            if(temp.next != null){
                temp = temp.next;
            }
            else{
                break;
            }
            now = temp;
            if(temp.next != null){
                next = temp.next;
            }
            else{
                break;
            }

            pre.next = next;
            now.next = next.next;
            next.next = now;

            // temp = temp.next;
        }
        return list.next;
    }
}