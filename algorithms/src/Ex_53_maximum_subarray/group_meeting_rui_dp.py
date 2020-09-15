"""
Time complexity: O(n)
Space complexity: O(n)
"""

from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # boundary check
        if len(nums) == 1:
            return nums[0]

        # initialize a list to store the maximum sum till each index
        dp = [nums[0]] * len(nums)

        # store the maximum sum
        maximum_sum = nums[0]

        for i in range(1, len(nums)):
            # calculate the maximum sum till the current index
            dp[i] = max(dp[i-1] + nums[i], nums[i])

            maximum_sum = max(maximum_sum, dp[i])

        return maximum_sum


if __name__ == "__main__":
    solu = Solution()
    print(solu.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))    # expect 6

