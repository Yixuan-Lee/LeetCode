"""
Reference:
https://leetcode.com/problems/longest-increasing-subsequence/solution/

Idea:
top-down dynamic programming
store the recursive results in a 2d array called memo
memo[i][j] represents the length of LIS using nums[i] as the previous element considered to be included/not included
and using nums[j] as the current element considered to be included/not included in the LIS

Time complexity: O(n^2)  [TLE]
Space complexity: O(n^2)

"""

from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums or len(nums) == 0:
            return 0
        n = len(nums)
        # memo is n x (n+1)
        # because
        memo = [[-1] * (n + 1) for _ in range(n)]
        return self.__length_of_lis(nums, -1, 0, memo)

    def __length_of_lis(self, nums: List[int], prev_idx: int, curr_idx: int, memo: List[List[int]]) -> int:
        if curr_idx == len(nums):
            return 0
        if memo[prev_idx+1][curr_idx] != -1:
            return memo[prev_idx+1][curr_idx]
        LIS1 = 0    # take the current element
        if prev_idx < 0 or nums[prev_idx] < nums[curr_idx]:
            LIS1 = self.__length_of_lis(nums, curr_idx, curr_idx+1, memo) + 1
        LIS2 = self.__length_of_lis(nums, prev_idx, curr_idx+1, memo)   # not take the current element
        # update memo
        # we consider
        memo[prev_idx+1][curr_idx] = max(LIS1, LIS2)
        return memo[prev_idx+1][curr_idx]


if __name__ == '__main__':
    solu = Solution()
    print(solu.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))   # 4
