from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxArea = 0
        for i in range(len(height)):
            for j in range(i, len(height)):
                maxArea = max()
