/**
 * Idea:
 * make two pointers - slow and fast pointers
 * fast pointer moves n steps ahead in advance
 * then slow and fast move forward one step at a time
 * when fast.next is null, at the same time, slow is pointing to the n-th node from the end of list
 *
 * Author: Chen long
 * Time complexity: O(n)
 * Space complexity: O(1)
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // create a dummy node
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        // find position
        ListNode slow = dummy;
        ListNode fast = dummy;

        // move fast pointer n step forward
        for (int i = 0; i < n + 1; i++) {
            fast = fast.next;
        }

        // move slow and fast
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        // so far, we want to delete the node pointed by slow
        slow.next = slow.next.next;

        return dummy.next;
    }
}

