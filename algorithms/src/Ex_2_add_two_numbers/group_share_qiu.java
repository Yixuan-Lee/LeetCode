/**
 * Idea:
 *
 *
 * Author: Qiu
 * Time complexity: O(max(n, m))
 * Space complexity: O(max(n, m)) + 1
 *
 * where
 * m: length of list 1
 * n: length of list 2
 */


/**
 * Definition for singly-linked list.
 */
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    ListNode result = new ListNode(0);
    ListNode out = result;

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = 0;
        int one, ten = 0;
        while (l1 != null || l2 != null) {
            int x = (l1 != null) ? l1.val : 0;
            int y = (l2 != null) ? l2.val : 0;

            sum = x + y;

            out.next = new ListNode(0);
            out = out.next;

            out.val = (sum + ten) % 10;
            ten = (sum + ten) / 10;

            if (l1 != null)
                l1 = l1.next;
            if (l2 != null)
                l2 = l2.next;
        }
        if (ten > 0)
            out.next = new ListNode(ten);

        return result.next;
    }
}
