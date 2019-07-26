// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：
// 给定一个链表: 1->2->3->4->5, 和 n = 2.
// 当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 说明：
// 给定的 n 保证是有效的。

// 进阶：
// 你能尝试使用一趟扫描实现吗？

// 双指针，一遍遍历
// 第一个指针先遍历n个，然后两个指针一起遍历，当第一个指针遍历到结尾时，第二个指针指向的是倒数第n个节点
// 新增头节点，可以将列表只有一个元素的情况和其他情况结合起来考虑

public class removeNthFromEnd {

    public static void main(String[] args){
        removeNthFromEnd test = new removeNthFromEnd();
        ListNode node = new ListNode(1);
        ListNode head = node;
        // node.next = new ListNode(2);
        // node = node.next;
        // node.next = new ListNode(3);
        // node = node.next;
        // node.next = new ListNode(4);
        // node = node.next;
        // node.next = new ListNode(5);
        // node = node.next;
        // node.next = new ListNode(6);
        // node = node.next;
        int n = 1;
        ListNode list = test.removeNthFromEnd(head, n);
        while(list != null){
            System.out.println(list.val);
            list = list.next;
        }
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode first = temp, second = temp;
        int count = n + 1;
        while(first != null && count > 0){
            first = first.next;
            count --;
        }
        while(first != null){
            second = second.next;
            first = first.next;
        }
        second.next = second.next.next;
        return temp.next;
    }
}