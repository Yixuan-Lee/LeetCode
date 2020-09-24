# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if head.next is None:
            return head

        count = 0
        itor = head
        while itor is not None:
            itor = itor.next
            count += 1
        # print(count)

        move_forward = count // 2
        # print(move_forward)
        middle = head
        for i in range(move_forward):
            middle = middle.next

        return middle
