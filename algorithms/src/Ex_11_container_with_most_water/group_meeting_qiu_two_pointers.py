from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxArea = (right - left) * min(height[left], height[right])

        while right > left:
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
            currArea = (right - left) * min(height[left], height[right])
            maxArea = max(maxArea, currArea)
        return maxArea


if __name__ == "__main__":
    solu = Solution()
    print(solu.maxArea([1,8,6,2,5,4,8,3,7]))    # expect 49
