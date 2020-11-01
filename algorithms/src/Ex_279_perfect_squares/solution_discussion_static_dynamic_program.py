"""
Reference:
https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)

Idea:
keep updating the memo which records the least number of perfect square for each integer starting from 1.
the only difference is that we dynamically add the least number to our memo

Time complexity: O(n * sqrt(n)) = O(n^(3/2))
Space complexity: O(n)

"""


class Solution:
    def numSquares(self, n: int) -> int:
        if n <= 0:
            return 0

        count_perfect_square = [0]
        while len(count_perfect_square) <= n:
            i = len(count_perfect_square)
            count = float('inf')
            j = 1
            while j*j <= i:
                count = min(count, count_perfect_square[i - j*j] + 1)
                j += 1
            count_perfect_square.append(count)
        return count_perfect_square[-1]


if __name__ == '__main__':
    solu = Solution()
    print(solu.numSquares(12))  # 3
    print(solu.numSquares(13))  # 2
