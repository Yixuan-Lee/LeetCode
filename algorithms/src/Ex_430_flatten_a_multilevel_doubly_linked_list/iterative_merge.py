"""
Reference:
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/150321/Easy-Understanding-Java-beat-95.7-with-Explanation

Idea:
There are 2 cases:
    case 1: current node does not have child
            then go to next node

    case 2: current node has child nodes
            then first find the last node of the child linked list
            then connect current's next node in the main list with the last node of the child linked list
            then connect current node with the current's child
            then set current's child pointer to null
            then go to next node (i.e. previously first child node)
                                 (so if previously first child node has child nodes, it will process)

Time complexity: O(n)
Space complexity: O(1)

"""

# Definition for a Node.
class Node:
    def __init__(self, val, prev=None, next=None, child=None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child


class Solution:
    def flatten(self, head: Node) -> Node:
        if head is None:
            return head

        itor = head
        while itor is not None:
            # case 1: if no child, proceed
            if itor.child is None:
                itor = itor.next
            else:
                # if has child, then find the tail
                tail = itor.child
                while tail.next is not None:
                    tail = tail.next

                # connect the tail with itor.next
                tail.next = itor.next
                if itor.next is not None:
                    itor.next.prev = tail

                # connect itor with itor.child
                itor.child.prev = itor
                itor.next = itor.child

                # empty the current child pointer
                itor.child = None

                # move to next node
                itor = itor.next

        return head


if __name__ == '__main__':
    # test case 1
    Node_t1_3 = Node(3)
    Node_t1_2 = Node(2)
    Node_t1_1 = Node(1, None, Node_t1_2, Node_t1_3)
    Node_t1_2.prev = Node_t1_1

    solu = Solution()
    res1 = solu.flatten(Node_t1_1)
    val1 = []
    it = res1
    while it is not None:
        val1.append(it.val)
        it = it.next
    print(val1)     # expect [1, 3, 2]

    # test case 2
    Node_t2_12 = Node(12)
    Node_t2_11 = Node(11, None, Node_t2_12, None)
    Node_t2_12.prev = Node_t2_11

    Node_t2_10 = Node(10)
    Node_t2_9 = Node(9, None, Node_t2_10, None)
    Node_t2_10.prev = Node_t2_9
    Node_t2_8 = Node(8, None, Node_t2_9, Node_t2_11)
    Node_t2_9.prev = Node_t2_8
    Node_t2_7 = Node(7, None, Node_t2_8, None)
    Node_t2_8.prev = Node_t2_7

    Node_t2_6 = Node(6)
    Node_t2_5 = Node(5, None, Node_t2_6, None)
    Node_t2_6.prev = Node_t2_5
    Node_t2_4 = Node(4, None, Node_t2_5, None)
    Node_t2_5.prev = Node_t2_4
    Node_t2_3 = Node(3, None, Node_t2_4, Node_t2_7)
    Node_t2_4.prev = Node_t2_3
    Node_t2_2 = Node(2, None, Node_t2_3, None)
    Node_t2_3.prev = Node_t2_2
    Node_t2_1 = Node(1, None, Node_t2_2, None)
    Node_t2_2.prev = Node_t2_1

    res2 = solu.flatten(Node_t2_1)
    val2 = []
    it = res2
    while it is not None:
        val2.append(it.val)
        it = it.next
    print(val2)     # expect [1, 2, 3, 7, 8, 11, 12, 9, 10, 4, 5, 6]
