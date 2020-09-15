from typing import List
import sys as sys


class Solution:
    # linear time
    # def maxSubArray(self, nums: List[int]) -> int:
    #     maxSum = -sys.maxsize - 1
    #     curr = 0
    #     for num in nums:
    #         if curr > 0:
    #             curr += num
    #         else:
    #             curr = num
    #         maxSum = max(maxSum, curr)
    #     return maxSum

    # dynamic programming
    def maxSubArray(self, nums: List[int]) -> int:
        # define a list for indicating max in dp[0:i]
        dp = list()
        dp.append(nums[0])
        max = dp[0]
        # solve the sub-problems based the previous sub-problems
        for i in range(1, len(nums)):
            if dp[i - 1] < 0:
                dp.append(nums[i])
            else:
                dp.append(dp[i - 1] + nums[i])
            # update max
            if max < dp[i]:
                max = dp[i]
        return max


if __name__ == '__main__':
    s = Solution()
    nums = [int(x) for x in input().split(",")]
    ans = s.maxSubArray(nums)
    print(ans)
