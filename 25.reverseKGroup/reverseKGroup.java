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

// 创建一个k大小的栈，然后每k个将节点存入栈中反转
// 然后采用递归的形式，将剩下的部分以同样的方式处理，但是这样做好像使用的空间不是O(1)
// 所以不采用递归的形式，而采用循环的形式，复用栈，处理完k个元素后，继续循环处理下k个元素
// 而创建了大小为k的栈，空间复杂度也就不是O(1)了

// 采用O(1)空间的方式，就是只对指针进行操作
// 所以每k个元素取下来，然后将之反转，然后接在原始的位置，而这个操作不用开辟另外的空间，只需要将元素之间的指针进行变换

public class reverseKGroup {

    public static void main(String[] args){
        reverseKGroup test = new reverseKGroup();
        int k = 3;
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

        ListNode result = test.reverseKGroup(l1_head, k);
        // ListNode result = test.reverse(l1_head);
        while(result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }

// 每k个元素一组
// 交换指针时候想的不是很清楚
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode list = new ListNode(0);
        list.next = head;
        ListNode curr = list, pre = list, last = null, next = null;
        while(curr != null){
            for(int i = 0; i < k && curr != null; i ++){
                curr = curr.next;
            }
            if(curr == null){
                break;
            }
            last = pre.next;
            next = curr.next;

            curr.next = null;
            pre.next = reverse(last);
            last.next = next;
            pre = last;
            curr = pre;
        }

        return list.next;
    }

// 反转k个元素
    public ListNode reverse(ListNode head){
        ListNode curr = head, pre = null, next = null;
        while(curr != null){
            next = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }
}