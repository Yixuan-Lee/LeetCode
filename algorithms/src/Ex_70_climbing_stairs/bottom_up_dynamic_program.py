"""
Idea:
bottom-up dynamic programming
use a memo to store the number of ways to the top
base cases:
    1) the second last floor only has 1 way to the top
    2) the third last floor has 2 ways to the top
from the end the the beginning, iteratively fill the memo.

Time complexity: O(n)
Space complexity: O(n)

"""

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1    # 1
        if n == 2:
            return 2    # 1 + 1, 2
        steps = [0] * n
        # initialize the last two
        steps[n-1] = 1  # current = n-1, can only climb 1 stair
        steps[n-2] = 2  # current = n-2, can climb 1 or 2 stairs

        for i in range(n-3, -1, -1):
            steps[i] = steps[i+1] + steps[i+2]
        return steps[0]


if __name__ == '__main__':
    solu = Solution()
    print(solu.climbStairs(2))  # 2
    print(solu.climbStairs(3))  # 3
