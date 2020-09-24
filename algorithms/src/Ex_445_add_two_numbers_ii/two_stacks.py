"""
Reference:
https://leetcode.com/problems/add-two-numbers-ii/discuss/92623/Easy-O(n)-Java-Solution-using-Stack

Time complexity: O(m+n)
Space complexity: O(n)

"""
from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # boundary checking
        if l1 is None:
            return l2
        if l2 is None:
            return l1

        stack_l1: List[int] = []
        stack_l2: List[int] = []
        itor1 = l1
        itor2 = l2
        while itor1 is not None:
            stack_l1.append(itor1.val)
            itor1 = itor1.next
        while itor2 is not None:
            stack_l2.append(itor2.val)
            itor2 = itor2.next

        current = ListNode(-1)
        carry = 0
        while len(stack_l1) > 0 or len(stack_l2) > 0:
            sum = 0
            if len(stack_l1) > 0:
                sum += stack_l1.pop()
            if len(stack_l2) > 0:
                sum += stack_l2.pop()

            current.val = (sum + carry) % 10
            carry = (sum + carry) // 10

            # make a temporary head node
            temp = ListNode(-1)
            temp.next = current
            current = temp
        if carry > 0:
            current.val = carry

        return current if current.val != -1 else current.next


def print_list(head: ListNode):
    curr = head
    while curr is not None:
        print(curr.val, end=' ')
        curr = curr.next
        if curr is not None:
            print('->', end=' ')


if __name__ == '__main__':
    solu = Solution()
    list1_1 = ListNode(7,
                       ListNode(2,
                                ListNode(4,
                                         ListNode(3, None))))
    list1_2 = ListNode(5,
                       ListNode(6,
                                ListNode(4, None)))
    res1 = solu.addTwoNumbers(list1_1, list1_2)
    print_list(res1)
