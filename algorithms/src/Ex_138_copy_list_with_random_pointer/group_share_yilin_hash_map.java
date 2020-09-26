/**
 * Idea:
 * use hash map to store the random pointer
 *
 * Author: Yilin
 * Time complexity: O(n)
 * Space complexity: O(n)
 *
 */

/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        // check input
        if (head == null) {
            return null;
        }

        HashMap<Node, Node> map = new HashMap<>();

        Node current = head;
        // copy nodes
        while (current != null) {
            map.put(current, new Node(current.val));
            current = current.next;
        }
        // add links
        current = head;
        while (current != null) {
            // set next pointer
            map.get(current).next = map.get(current.next);
            // set random pointer
            map.get(current).random = map.get(current.random);

            current = current.next;
        }

        return map.get(head);
    }
}
