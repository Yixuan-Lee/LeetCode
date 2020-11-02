"""
Reference:
https://leetcode.com/problems/longest-increasing-subsequence/solution/

Idea:
bottom-up dynamic programming
this method relies on the fact that the longest increasing sub-sequence possible upto the i^{th}
index in a given array is independent of the elements coming later on in the array.
Thus, if we know the length of the LIS upto i^{th} index, we can figure out the length of the LIS
possible by including the (i+1)^{th} element based on the elements with indices jj such that
0 <= j <= (i + 1)

dp[i] represents the length of the longest increasing sub-sequence possible considering the array elements
up to the i^{th} index only, by necessarily including the i^{th} element.
in order to find out dp[i], we need to append nums[i] in every possible increasing sub-sequence upto (i-1)^{th}
such that the new sub-sequence upto i^{th} element is also an increasing sub-sequence.

formulas:
    dp[i] = max(dp[j]) + 1 , where 0 <= j < i and nums[i] > nums[j]

the final result will be:
    max(dp[i]) , where 0 <= i < len(nums)

Time complexity: O(n^2)
Space complexity: O(n)

"""

from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums or len(nums) == 0:
            return 0
        dp = [1] * len(nums)
        for i in range(1, len(nums)):
            max_length = 0
            for j in range(i):
                if nums[i] > nums[j]:
                    max_length = max(max_length, dp[j])
            dp[i] = max_length + 1
        return max(dp)


if __name__ == '__main__':
    solu = Solution()
    print(solu.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))   # 4
    print(solu.lengthOfLIS([4, 10, 4, 3, 8, 9])) # 3
