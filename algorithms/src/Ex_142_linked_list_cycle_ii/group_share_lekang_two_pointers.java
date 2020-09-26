/**
 * Idea:
 * set up two pointers - slow and fast
 * meet once: set slow -> head
 * slow and fast move 1 step at a time
 * next time meet point -> first node in cycle
 *
 * References:
 * https://hui-wang.info/2017/11/18/%E5%8A%A8%E7%94%BB%E8%A7%A3%E9%87%8A%E5%A6%82%E4%BD%95%E6%B1%82%E5%8D%95%E9%93%BE%E8%A1%A8%E7%8E%AF%E5%85%A5%E5%8F%A3%E7%82%B9/
 * https://www.youtube.com/watch?v=UkKBPGt5Nok&t=287s
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
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                break;
            }
        }
        if (fast == null || fast.next == null) {
            // in case there is no cycle
            return null;
        }
        // so far, slow and fast are pointing to the same node

        // reset slow to head
        slow = head;
        // then move slow and fast pointers one step at a time
        while (slow != fast) {
            fast = fast.next;
            slow = slow.next;
        }
        // the next time when slow and fast meet is the time when slow and fast are pointing to the first node in the cycle
        return slow;
    }
}

