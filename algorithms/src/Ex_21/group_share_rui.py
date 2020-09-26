"""
Idea:
create a dummy node before the first node in the new linked list

Author: Rui
Time complexity: O(max(m+n))
Space complexity: O(1)

"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        tail = dummy

        # compare the heads of two linked list
        while l1 and l2:
            if l1.val > l2.val:
                tail.next = l2
                l2 = l2.next
            else:
                tail.next = l1
                l1 = l1.next
            tail = tail.next

        # splice the nodes left in one of the two linked list
        if l1 is not None:
            tail.next = l1
        if l2 is not None:
            tail.next = l2

        return dummy.next

