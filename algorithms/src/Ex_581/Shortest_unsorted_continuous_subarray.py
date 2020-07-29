"""
This question relates to "Monotonic Stack" (单调栈).

"Monotonic Stack" is a stack that follows a specific order, usually ascending
or descending order, when pushing each item, if the order breaks when pushing
the current item, then pop until the order holds for the current item.

This question we need to do twice:
    1. Build an ascending (non-decreasing for specific) monotonic stack from
       the beginning to end to find the left bound
    2. Build a descending (non-increasing for specific) monotonic stack from
       the end to beginning to find the right bound

credit: https://www.bilibili.com/video/BV1yx411j7yM?from=search&seid=17003902662158524966
"""


class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return 0

        # from the beginning to end
        ascending_stack = list()    # record the indices instead of values
        ascending_stack.append(0)
        left_bound_index = len(nums) - 1  # record the first left index that is popped in order to hold the ascending order
        for i in range(1, len(nums)):
            if len(ascending_stack) == 0 or nums[i] >= nums[ascending_stack[-1]]:
                # order still holds
                ascending_stack.append(i)
            else:
                # order does not holds when pushing the current item
                # pop until the order holds and record the minimum popped indices
                while len(ascending_stack) > 0 and nums[i] < nums[ascending_stack[-1]]:
                    left_bound_index = min(ascending_stack.pop(), left_bound_index)
                ascending_stack.append(i)

        # from the end to beginning
        descending_stack = list()
        descending_stack.append(len(nums) - 1)
        right_bound_index = 0   # record the first right index that is popped in order to hold the descending order
        for i in range(len(nums) - 2, -1, -1):
            if len(descending_stack) == 0 or nums[i] <= nums[descending_stack[-1]]:
                # order still holds
                descending_stack.append(i)
            else:
                # order does not holds when pushing the current item
                # pop until the order holds and record the maximum popped indices
                while len(descending_stack) > 0 and nums[i] > nums[descending_stack[-1]]:
                    right_bound_index = max(descending_stack.pop(), right_bound_index)
                descending_stack.append(i)

        # print(left_bound_index, right_bound_index)
        return right_bound_index - left_bound_index + 1 if right_bound_index > left_bound_index else 0


if __name__ == '__main__':
    s = Solution()
    nums = [2, 6, 4, 8, 10, 9, 15]
    print(s.findUnsortedSubarray(nums))

    nums = [1, 2, 3, 3, 3]
    print(s.findUnsortedSubarray(nums))

    nums = [2, 3, 3, 2, 4]
    print(s.findUnsortedSubarray(nums))
