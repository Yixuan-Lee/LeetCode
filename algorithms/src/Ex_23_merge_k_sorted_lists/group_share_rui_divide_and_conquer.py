"""
Idea:
merge pairs of the lists in the main list iteratively

Author: Rui
Time complexity: O(n*log(k))
Space complexity: O(k)

where
k: length of lists
n: length of longest list in lists

"""

from typing import List


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if not lists or len(lists) == 0:
            return None

        while len(lists) > 1:   # time complexity: log(k)
            merged_list: List[ListNode] = list()
            # make list pairs
            for i in range(0, len(lists), 2):   # time complexity: O(max(len(l1), len(l2)))
                l1 = lists[i]
                l2 = lists[i + 1] if i + 1 < len(lists) else None
                # merge the list pair
                merged_list.append(self.merge_two_lists(l1, l2))

            # update the list of lists
            lists = merged_list

        return lists[0]

    def merge_two_lists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode()
        tail = dummy

        while l1 and l2:
            if l1.val > l2.val:
                tail.next = l2
                l2 = l2.next
            else:
                tail.next = l1
                l1 = l1.next
            tail = tail.next

        if l1:
            tail.next = l1
        if l2:
            tail.next = l2
        return dummy.next
