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

public class mergeKLists {

    public static void main(String[] args){
        mergeKLists test = new mergeKLists();
        ListNode l1 = new ListNode(1);
        ListNode l1_head = l1;
        l1.next = new ListNode(4);
        l1 = l1.next;
        l1.next = new ListNode(5);

        ListNode l2 = new ListNode(1);
        ListNode l2_head = l2;
        l2.next = new ListNode(3);
        l2 = l2.next;
        l2.next = new ListNode(4);

        ListNode l3 = new ListNode(2);
        ListNode l3_head = l3;
        l3.next = new ListNode(6);

        ListNode[] lists = new ListNode[]{l1_head, l2_head, l3_head};
        ListNode result = test.mergeKLists(lists);
        while(result != null){
            System.out.println(result.val);
            result = result.next;
        }
    }

    public ListNode mergeKLists(ListNode[] lists) {
        ListNode result = mergeSort(lists, 0, lists.length - 1);
        return result;
    }

    public ListNode mergeSort(ListNode[] lists, int start, int end) {
        int mid = start + (end - start) / 2;
        ListNode list1 = null, list2 = null, result = null;
        // System.out.println("start:" + start + ",end:" + end);
        if(start < end){
            if(start == end - 1){
                list1 = lists[start];
                list2 = lists[end];
            }
            else{
                list1 = mergeSort(lists, start, mid);
                list2 = mergeSort(lists, mid + 1, end);
            }
            result = mergeTwoLists(list1, list2);
        }
        else if(start == end){
            return lists[start];
        }
        return result;
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode list = new ListNode(0);
        ListNode head = list;
        int temp = 0;
        while(l1 != null && l2 != null){
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
        while(l1 != null){
            head.next = new ListNode(l1.val);
            head = head.next;
            l1 = l1.next;
        }
        while(l2 != null){
            head.next = new ListNode(l2.val);
            head = head.next;
            l2 = l2.next;
        }
        return list.next;
    }
}