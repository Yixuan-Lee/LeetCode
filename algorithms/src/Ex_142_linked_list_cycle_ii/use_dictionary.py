from typing import Dict

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        recorder: Dict[ListNode, bool] = dict()

        itor = head
        while itor is not None:
            if recorder.get(itor, False) is False:
                recorder[itor] = True
            else:
                return itor
            itor = itor.next

        return None

def get_test_case_1() -> ListNode:
    node_3 = ListNode(3)
    node_2 = ListNode(2)
    node_0 = ListNode(0)
    node_n4 = ListNode(-4)

    node_3.next = node_2
    node_2.next = node_0
    node_0.next = node_n4
    node_n4.next = node_2
    return node_3


def get_test_case_3() -> ListNode:
    node_1 = ListNode(1)
    return node_1


if __name__ == '__main__':
    solu = Solution()
    head1 = get_test_case_1()
    print(solu.detectCycle(head1))

    head3 = get_test_case_3()
    print(solu.detectCycle(head3))
