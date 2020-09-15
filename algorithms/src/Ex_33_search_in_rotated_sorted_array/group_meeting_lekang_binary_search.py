"""
Time complexity: O(logn)
Space complexity: O(1)
"""

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # find the index of pivot point (the smallest value's index)
        low = 0
        high = len(nums) - 1
        # because we are sure there is an answer, there is no equal sign
        while low < high:
            mid = int(low + (high - low) / 2)
            if nums[mid] >= nums[high]:
                # meaning [low, high] is ascending
                low = mid + 1
            else:
                high = mid

        # to see which part does the target belong
        pivot = low
        if target <= nums[-1] and target >= nums[pivot]:
            # the target may be in the second array
            low = pivot
            high = len(nums) - 1
        else:
            # the target may be in the first array
            low = 0
            high = pivot

        # binary search
        # because we are not sure there is an answer, the condition should
        # have the equal sign
        while low <= high:
            mid = int(low + (high - low) / 2)
            if nums[mid] > target:
                high = mid - 1
            elif nums[mid] < target:
                low = mid + 1
            else:
                return mid
        return -1


if __name__ == '__main__':
    solu = Solution()
    print(solu.search([4,5,6,7,0,1,2], 0))  # expect 0
    print(solu.search([4,5,6,7,0,1,2], 3))  # expect -1
    print(solu.search([1], 0))  # expect -1
