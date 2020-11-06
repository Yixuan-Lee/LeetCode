"""
Idea:
step 1: make all 0s in the right places
if p0 meets 0, go next
if p0 meets 1, search from p2-1 to p0+1, find a 0 and swap with p0
if p0 meets 2, swap with p2

step 2: reorder the rest 1s and 2s in nums

Time complexity: O(n)
Space complexity: O(1)

"""

from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        p0 = 0
        p2 = len(nums) - 1
        while p0 < p2:
            if nums[p0] == 2:
                # swap with p2
                nums[p0], nums[p2] = nums[p2], nums[p0]
                p2 -= 1
            elif nums[p0] == 0:
                p0 += 1
            elif nums[p0] == 1:
                p1 = p2
                while p1 > p0 and nums[p1] != 0:
                    p1 -= 1
                if nums[p1] != 0:
                    # meaning there is no 0 between nums[p0+1 ... p2]
                    break
                else:
                    # swap p0 and p1
                    nums[p0], nums[p1] = nums[p1], nums[p0]
                    p0 += 1
        # so far, nums[0 ... p0-1] are all 0s
        # next, make numbers nums[p0 ... p2] in order
        p1 = p0
        while p1 < p2:
            if nums[p1] == 1:
                p1 += 1
            elif nums[p1] == 2:
                nums[p1], nums[p2] = nums[p2], nums[p1]
                p2 -= 1


if __name__ == '__main__':
    solu = Solution()
    solu.sortColors([2, 0, 2, 1, 1, 0])
    solu.sortColors([2, 0, 1])
    solu.sortColors([0, 0, 1, 2, 1, 2])
