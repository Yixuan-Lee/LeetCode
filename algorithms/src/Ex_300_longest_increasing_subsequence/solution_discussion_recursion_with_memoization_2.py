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

from typing import List, Set, Tuple


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums or len(nums) == 0:
            return 0
        n = len(nums)
        # memo is n x (n+1)
        # because we append a negative infinity to the beginning of nums for considering the first number
        # in original nums to be included/not included
        memo = [[-1] * (n+1) for _ in range(n)]
        all_combo = set()
        res = self.__length_of_lis([float('-inf')] + nums, 0, 1, memo, 0, [], all_combo)
        for combo in all_combo:
            print(combo)
        return res

    def __length_of_lis(self, nums: List[int], prev_idx: int, curr_idx: int, memo: List[List[int]], curr_length: int, curr_nums: List[int], combo: Set[Tuple[int]]) -> int:
        if curr_idx == len(nums):
            return 0
        if memo[prev_idx][curr_idx] != -1:
            return memo[prev_idx][curr_idx]
        LIS1 = 0    # take the current element
        if nums[prev_idx] < nums[curr_idx]:
            combo.add(tuple(curr_nums+[nums[curr_idx]]))
            LIS1 = self.__length_of_lis(nums, curr_idx, curr_idx+1, memo, curr_length+1, curr_nums+[nums[curr_idx]], combo) + 1
        combo.add(tuple(curr_nums))
        LIS2 = self.__length_of_lis(nums, prev_idx, curr_idx+1, memo, curr_length, curr_nums, combo)   # not take the current element
        # update memo
        # we consider nums[prev_idx] to be the previous element and consider nums[curr_idx] to be included/not included
        memo[prev_idx][curr_idx] = max(LIS1, LIS2)

        return memo[prev_idx][curr_idx]


if __name__ == '__main__':
    solu = Solution()
    print(solu.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))   # 4
