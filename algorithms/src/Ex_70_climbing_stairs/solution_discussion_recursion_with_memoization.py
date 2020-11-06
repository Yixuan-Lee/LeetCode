"""
Reference:
https://leetcode.com/problems/climbing-stairs/solution/

Idea:
memoization approach
optimal substructure:
    climbStairs(i, n) = climbStairs(i+1, n) + climbStairs(i+2, n)
store the intermediate results, because we know for sure the intermediate results
are overlapped, so time complexity is reduced to O(n)

Time complexity: O(n)
Space complexity: O(n)

"""

from typing import List


class Solution:
    def climbStairs(self, n: int) -> int:
        memo = [0] * (n+1)
        return self.__recursion(0, n, memo)

    def __recursion(self, curr_floor: int, target_floor: int, memo: List[int]) -> int:
        if curr_floor > target_floor:
            return 0
        if curr_floor == target_floor:
            return 1
        if memo[curr_floor] != 0:
            return memo[curr_floor]

        memo[curr_floor] = self.__recursion(curr_floor+1, target_floor, memo) + self.__recursion(curr_floor+2, target_floor, memo)
        return memo[curr_floor]


if __name__ == '__main__':
    solu = Solution()
    print(solu.climbStairs(2))  # 2
    print(solu.climbStairs(3))  # 3
