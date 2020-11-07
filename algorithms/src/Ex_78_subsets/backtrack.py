"""
Idea:
define a backtracking function that appends all possible unique subsets of
a certain length to ans

Time complexity:
Space complexity:

"""

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans: List[List[int]] = list()
        for length in range(len(nums) + 1):
            self.__backtrack(nums, [], 0, length, ans)
        return ans

    def __backtrack(self, nums: List[int], curr: List[int], start_idx: int, length: int, ans: List[List[int]]):
        # base case
        if len(curr) == length:
            ans.append(curr)
            return
        for i in range(start_idx, len(nums)):
            self.__backtrack(nums, curr + [nums[i]], i+1, length, ans)


if __name__ == '__main__':
    solu = Solution()
    print(solu.subsets([1, 2, 3]))


