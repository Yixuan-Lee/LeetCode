from typing import List

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

        st1: List[ListNode] = list()
        st2: List[ListNode] = list()
        itor1 = l1
        itor2 = l2
        while itor1 is not None:
            st1.append(itor1.val)
            itor1 = itor1.next
        while itor2 is not None:
            st2.append(itor2.val)
            itor2 = itor2.next

        carry = 0
        global curr
        prev = None
        while len(st1) or len(st2) or carry:
            summation = 0
            if len(st1):
                summation += st1.pop()
            if len(st2):
                summation += st2.pop()

            remain = (summation + carry) % 10
            carry = (summation + carry) // 10
            curr = ListNode(remain, prev)
            prev = curr

        return curr


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
