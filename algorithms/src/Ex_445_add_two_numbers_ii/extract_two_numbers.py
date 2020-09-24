# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # extract the number 1 in l1
        num1 = l1.val
        it1 = l1.next
        while it1 is not None:
            num1 = num1 * 10 + it1.val
            it1 = it1.next

        # extract the number 2 in l2
        num2 = l2.val
        it2 = l2.next
        while it2 is not None:
            num2 = num2 * 10 + it2.val
            it2 = it2.next

        # sum
        summation = num1 + num2

        # construct a new list
        head = ListNode(summation % 10)
        summation = summation // 10
        while summation > 0:
            old_head = head
            head = ListNode(summation % 10, old_head)
            summation = summation // 10

        return head


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
