"""
Reference:
https://leetcode.com/problems/climbing-stairs/solution/

Idea:
we've known the optimal substructure:
    climbStairs(i, n) = climbStairs(i+1, n) + climbStairs(i+2, n)
the optimal solution can be constructed efficiently from optimal solutions of
its sub-problems.

there are 2 ways to reach i-th step:
    1) take a single step from (i-1)-th step
    2) take a step of 2 from (i-2)-th step

dp[i] : the total number of ways to reach i-th step
thus
    dp[i] = dp[i-1] + dp[i-2]
base cases:
    1) there is only 1 way to reach step 1
    2) there is 2 ways to reach step 2

Time complexity: O(n)
Space complexity: O(n)

"""


class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        dp = [0] * (n+1)
        # base cases
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n]


if __name__ == '__main__':
    solu = Solution()
    print(solu.climbStairs(2))  # 2
    print(solu.climbStairs(3))  # 3
