"""
Idea:
maintain a memo which records the least number of perfect square.
try the largest perfect square first.

Time complexity: [TLE]
Space complexity: O(n)

"""

import math
from typing import List


class Solution:
    def numSquares(self, n: int) -> int:
        if n <= 0:
            return 0

        # store the least number of perfect square numbers for 1-n (index 0 is not used)
        memo = [-1] * (n+1)
        # initialize memo
        for i in range(math.floor(math.sqrt(n)), 0, -1):
            memo[i**2] = 1
        _ = self.backtrack(n, memo)
        return memo[-1]

    def backtrack(self, rest: int, memo: List[int]) -> int:
        if rest <= 0:
            return -1
        if memo[rest] != -1:
            return memo[rest]

        for i in range(math.floor(math.sqrt(rest)), 0, -1):
            num = self.backtrack(rest - i**2, memo)
            if num != -1:
                if memo[rest] != -1:
                    memo[rest] = min(num + 1, memo[rest])
                else:
                    memo[rest] = num + 1
        return memo[rest]


if __name__ == '__main__':
    solu = Solution()
    print(solu.numSquares(12))  # 3
    print(solu.numSquares(13))  # 2
