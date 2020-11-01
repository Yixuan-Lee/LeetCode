"""
Reference:
https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)

Idea:
leverage Lagrange's Four Square theorem, separately check whether 1,2,3,4 is the possible result

Time complexity: O(sqrt(n)) = O(n^(1/2))
Space complexity: O(1)

"""

import math


class Solution:
    def numSquares(self, n: int) -> int:
        # check whether 1 is the result
        if self.__is_square(n):
            return 1

        # based on Lagrange's Four Square theorem, there are only 4 possible results: 1, 2, 3, 4
        # check whether 4 is the result
        while (n & 3) == 0:   # equivalent to: n % 4 == 0
            n >>= 2
        if n & 7 == 7:  # equivalent to: n % 8 == 7
            return 4

        # check whether 2 is the result
        sqrt_n = int(math.sqrt(n))
        for i in range(1, sqrt_n+1):
            if self.__is_square(n - i*i):
                return 2

        # only 3 is the possible result
        return 3

    def __is_square(self, n: int) -> bool:
        return int(math.sqrt(n)) ** 2 == n


if __name__ == '__main__':
    solu = Solution()
    print(solu.numSquares(12))  # 3
    print(solu.numSquares(13))  # 2
