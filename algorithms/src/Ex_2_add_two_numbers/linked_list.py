# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 is None:
            return l2
        if l2 is None:
            return l1

        itor1 = l1
        itor2 = l2
        carry = 0
        # here, i decided to just allocate a new linked list in order to not affect l1 and l2
        curr = ListNode(-1)
        head = curr
        prev = None # pointing to the previous node of curr
        while itor1 is not None and itor2 is not None:
            sum = itor1.val + itor2.val + carry
            base = sum % 10
            carry = sum // 10

            curr.val = base
            # allocate a node for the next digit
            next = ListNode(-1)
            curr.next = next
            prev = curr
            curr = next

            itor1 = itor1.next
            itor2 = itor2.next

        if itor1 is not None:
            # meaning trailing elements in l1 are not considered
            while itor1:
                sum = itor1.val + carry
                base = sum % 10
                carry = sum // 10

                curr.val = base
                next = ListNode(-1)
                curr.next = next
                prev = curr
                curr = next

                itor1 = itor1.next

            if carry > 0:
                curr.val = carry
        elif itor2 is not None:
            # meaning trailing elements in l2 are not considered
            while itor2:
                sum = itor2.val + carry
                base = sum % 10
                carry = sum // 10

                curr.val = base
                next = ListNode(-1)
                curr.next = next
                prev = curr
                curr = next

                itor2 = itor2.next

            if carry > 0:
                curr.val = carry
        elif carry > 0:
            curr.val = carry

        # remove the last node if necessary
        if curr.val == -1:
            prev.next = None

        return head

