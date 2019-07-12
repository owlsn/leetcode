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

class addTwoNumbers {

    public static void main(String[] args){
        addTwoNumbers test = new addTwoNumbers();
        ListNode l1 = new ListNode(1);
        l1.next = new ListNode(8);
        ListNode l2 = new ListNode(0);
        
        ListNode result = test.addTwoNumbers(l1, l2);
        while(result != null){
            System.out.print(result.val + "->");
            result = result.next;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        //进位
        int add = 0;
        //结果链表表头
        ListNode result = new ListNode(0);
        ListNode pre = result;
        ListNode index = result;
        //和
        int sum = 0;
        while((l1 != null || l2 != null) || add != 0){
            if(index == null){
                index = new ListNode(0);
                pre.next = index;
            }
            if(l1 == null && l2 != null){
                sum = l2.val + add;
                l2 = l2.next;
            }
            else if(l2 == null && l1 != null){
                sum = l1.val + add;
                l1 = l1.next;
            }
            else if(l1 == null && l2 == null){
                sum = add;
            }
            else 
            {
                sum = l1.val + l2.val + add;
                l1 = l1.next;
                l2 = l2.next;
            }
            add = 0;
            if(sum >= 10){
                sum -= 10;
                add = 1;
            }

            index.val = sum;
            pre = index;
            index = index.next;
            sum = 0;
        }
        

        return result;
    }
}