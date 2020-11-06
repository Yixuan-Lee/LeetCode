"""
Reference:
https://leetcode.com/problems/climbing-stairs/solution/

Idea:
see bitnets-method-algorithm.png

Time complexity: O(logn)
Space complexity: O(1)

"""

from typing import List


class Solution:
    def climbStairs(self, n: int) -> int:
        q = [[1, 1], [1, 0]]
        res = self.pow(q, n)
        return res[0][0]

    def pow(self, a: List[List[int]], n: int):
        ret = [[1, 0], [0, 1]]
        while n > 0:
            if n & 1 == 1:
                ret = self.multiply(ret, a)
            n >>= 1
            a = self.multiply(a, a)
        return ret

    def multiply(self, a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
        c = [[-1, -1], [-1, -1]]
        for i in range(2):
            for j in range(2):
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]
        return c


if __name__ == '__main__':
    solu = Solution()
    print(solu.climbStairs(2))  # 2
    print(solu.climbStairs(3))  # 3
