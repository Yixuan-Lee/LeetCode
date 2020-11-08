"""
Reference:
https://leetcode.com/problems/longest-increasing-subsequence/solution/

Idea:
find all increasing sub-sequences and return the longest one.
there are two cases:
    1. if current element > previous element
       consider two sub-cases:
          1.1 LIS1 containing the current element
          1.2 LIS2 not containing the current element
       we return the max(LIS1, LIS2)

    2. if current element < previous element
       we only return LIS2

Time complexity: O(2^n)
Space complexity: O(n^2)

"""

from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        return self.__length_of_lis(nums, float('-inf'), 0)

    def __length_of_lis(self, nums: List[int], prev_val: int, curr_idx: int) -> int:
        # return the number of increasing sub-sequences
        if curr_idx == len(nums):
            return 0

        LIS1 = 0    # taken the current element
        if nums[curr_idx] > prev_val:
            LIS1 = self.__length_of_lis(nums, nums[curr_idx], curr_idx+1) + 1
        LIS2 = self.__length_of_lis(nums, prev_val, curr_idx+1)   # not taken the current element
        return max(LIS1, LIS2)


if __name__ == '__main__':
    solu = Solution()
    print(solu.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))   # 4
    print(solu.lengthOfLIS([4, 10, 4, 3, 8, 9])) # 3
