from typing import Dict


# Definition for a Node.
class Node:
    pass

class Node:
    def __init__(self, x: int, next: Node = None, random: Node = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: Node) -> Node:
        if head is None:
            return head

        # key: random Node
        # val: current index
        old_node_2_index: Dict[Node, int] = dict()
        # key: current index
        # val: random Node's index
        index_2_randindex: Dict[int, int] = dict()

        # backup the random pointers
        itor = head
        index = 0
        while itor is not None:
            old_node_2_index[itor] = index
            index += 1
            itor = itor.next
        itor = head
        while itor is not None:
            if itor.random is not None:
                index_2_randindex[old_node_2_index[itor]] = old_node_2_index[itor.random]
            itor = itor.next

        # deepcopy the next pointers
        new_head = Node(head.val)
        prev = new_head
        curr = head.next
        index = 0
        index_2_new_node: Dict[int, index] = {
            index: new_head
        }
        index += 1
        while curr is not None:
            new_node = Node(curr.val)
            index_2_new_node[index] = new_node
            index += 1
            prev.next = new_node
            prev = prev.next
            curr = curr.next

        # assign the random pointers
        for idx in index_2_randindex:
            index_2_new_node[idx].random = index_2_new_node[index_2_randindex[idx]]

        return new_head


def print_list(head: Node) -> None:
    itor = head
    print('[ ', end='')
    while itor is not None:
        curr_val = itor.val
        rand_index = itor.random
        print('[' + str(curr_val) + ',' + str(rand_index) + ']', end=' ')

        itor = itor.next
    print(']')


if __name__ == '__main__':
    solu = Solution()

    # test case 1
    node_t1_1 = Node(1, None)
    node_t1_2 = Node(2, None)
    node_t1_1.next = node_t1_2
    node_t1_1.random = node_t1_2
    node_t1_2.random = node_t1_2
    res1 = solu.copyRandomList(node_t1_1)
    print_list(res1)

