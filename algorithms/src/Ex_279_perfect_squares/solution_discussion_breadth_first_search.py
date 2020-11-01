"""
Reference:
https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)

Idea:

Time complexity: O(n * sqrt(n)) = O(n^(3/2))
Space complexity: O(n)

"""

from collections import deque

class Solution:
    def numSquares(self, n: int) -> int:
        if n <= 0:
            return 0

        queue = deque([0])
        visited = {0}
        depth = 0
        while queue:
            size = len(queue)   # show how many times we need to loop in the while loop below
            depth += 1
            while size:
                u = queue.popleft()
                j = 1
                while u + j*j <= n:
                    v = u + j * j
                    if v == n:
                        # we found the solution
                        return depth
                    if v > n:
                        break
                    if v not in visited:
                        queue.append(v)
                        visited.add(v)
                    j += 1
                size -= 1
        return depth


if __name__ == '__main__':
    solu = Solution()
    print(solu.numSquares(12))  # 3
    print(solu.numSquares(13))  # 2
