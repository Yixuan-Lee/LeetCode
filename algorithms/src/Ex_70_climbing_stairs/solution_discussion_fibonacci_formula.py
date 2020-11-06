"""
Reference:
https://leetcode.com/problems/climbing-stairs/solution/

Idea:
see fibonacci-formula.png

this solution has a potential of number overflow when n becomes large

Time complexity: O(logn)
Space complexity: O(1)

"""

import math

class Solution:
    def climbStairs(self, n: int) -> int:
        sqrt5 = math.sqrt(5)
        fibn = math.pow((1+sqrt5)/2, n+1) - math.pow((1-sqrt5)/2, n+1)
        return int(fibn/sqrt5)


if __name__ == '__main__':
    solu = Solution()
    print(solu.climbStairs(2))  # 2
    print(solu.climbStairs(3))  # 3
