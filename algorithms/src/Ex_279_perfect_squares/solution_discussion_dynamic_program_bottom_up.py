"""
Reference:
https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)

Idea:
bottom up dynamic programming
use a memo to record the least number of perfect square for each integer starting from 1

Time complexity: O(n * sqrt(n)) = O(n^(3/2))
Space complexity: O(n)

"""


class Solution:
    def numSquares(self, n: int) -> int:
        if n <= 0:
            return 0
        count_perfect_square = [n] * (n+1)
        count_perfect_square[0] = 0
        for i in range(1, n+1):
            j = 1
            while j*j <= i:
                count_perfect_square[i] = min(count_perfect_square[i], count_perfect_square[i-j*j] + 1)
                j += 1
        return count_perfect_square[-1]


if __name__ == '__main__':
    solu = Solution()
    print(solu.numSquares(12))  # 3
    print(solu.numSquares(13))  # 2
