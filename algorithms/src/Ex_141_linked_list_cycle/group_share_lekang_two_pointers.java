/**
 * Idea:
 * set two pointers - slow and fast
 *
 * Author: Lekang
 * Time complexity: O(n)
 * Space complexity: O(1)
 *
 */

/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}

public class Solution {
    public boolean hasCycle(ListNode head) {
        // boundary checking
        if (head == null || head.next == null) {
            return false;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                // meaning there is a cycle
                return true;
            }
        }

        return false;
    }
}
