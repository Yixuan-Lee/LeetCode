"""
Reference:
https://leetcode.com/problems/sort-colors/discuss/26472/Share-my-at-most-two-pass-constant-space-10-line-solution

Idea:
swap all 0s to the left and all 2s to the right, then all 1s are left in the middle

Time complexity: O(2n) = O(n)
Space complexity: O(1)

"""

from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        second, zero = len(nums)-1, 0
        for i in range(second+1):
            while nums[i] == 2 and i < second:
                nums[i], nums[second] = nums[second], nums[i]
                second -= 1
            while nums[i] == 0 and i > zero:
                nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1


if __name__ == '__main__':
    solu = Solution()
    ts1 = [2, 0, 2, 1, 1, 0]
    solu.sortColors(ts1)
    print(ts1)
