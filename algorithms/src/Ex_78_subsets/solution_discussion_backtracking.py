"""
Reference:
https://leetcode.com/problems/subsets/solution/

Idea:
the goal is to find the power set from the sequence.
we can loop over the length of combination with the help of backtracking technique

Time complexity: O(n * 2^n)
Space complexity: O(n * 2^n)

"""

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        def backtrack(first=0, curr=[]) -> None:
            # first: index of first element
            # curr: current combination
            if len(curr) == k:
                res.append(curr[:])
                return
            for i in range(first, n):
                # add nums[i] into the current combination
                curr.append(nums[i])
                # use next integers to complete the combination
                backtrack(i+1, curr)
                # backtrack
                curr.pop()
        res = []
        n = len(nums)
        for k in range(n+1):
            backtrack()
        return res


if __name__ == '__main__':
    solu = Solution()
    print(solu.subsets([1, 2, 3]))
