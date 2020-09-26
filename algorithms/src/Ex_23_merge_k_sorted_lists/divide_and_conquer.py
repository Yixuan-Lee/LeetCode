from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        pass


def get_test_case_1() -> List[ListNode]:
    list_1 = ListNode(1, ListNode(4, ListNode(5)))
    list_2 = ListNode(1, ListNode(3, ListNode(4)))
    list_3 = ListNode(2, ListNode(6))
    return [list_1, list_2, list_3]


def get_test_case_2() -> List[ListNode]:
    return []


def get_test_case_3() -> List[ListNode]:
    return [[]]


if __name__ == '__main__':
    solu = Solution()

