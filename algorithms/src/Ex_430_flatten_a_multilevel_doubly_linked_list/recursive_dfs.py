"""
Idea:
Split the conditions into 3 cases:
    case 1: if no child, then proceed

    case 2: if the first child node does not have child,
            then make the second and following child nodes to be the child nodes of the first child node
            then insert the first child node just after the current node in the main list
            proceed to the inserted node (so that it will do for the same as soon as the last child node is added)

    case 3: if the first child node has child nodes
            then merge the child linked list and child's child linked list (recursively)
            then go to case 2

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

        current = head
        while current is not None:
            if current.child is None:
                # case 1: current node does not have child nodes
                current = current.next
            else:
                # case 2/3: current node has child node(s)
                # insert the children after current and
                # return the last child node inserted aftet current
                # which is used to update next if it is not none
                self.dfs(current, current.child, current.next)
                current.child = None    # set child pointer to None
                current = current.next

        return head

    def dfs(self, previous: Node, current: Node, pnext: Node):
        if current.child is not None:
            # case 3: the first child node has its child node(s)
            # then we first recursively merge the children linked list and grand-children linked list
            # and if grand-children linked list has its own child nodes, do recursively
            self.dfs(current, current.child, current.next)
            current.child = None    # set child pointer to None

        # case 2: the first child node does not have child nodes (or after mergine)
        # then first make the second child node (if it is not None) to be the first child node of the previous first child node
        if current.next is not None:
            current.child = current.next
            current.next.prev = None

        # then add the first child node between previous and previous.next
        previous.next = current
        if pnext is not None:
            pnext.prev = current
        current.next = pnext
        current.prev = previous


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
