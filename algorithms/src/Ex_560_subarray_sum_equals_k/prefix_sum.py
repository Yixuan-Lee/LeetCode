"""
Reference:
https://leetcode.com/problems/subarray-sum-equals-k/discuss/102106/Java-Solution-PreSum-%2B-HashMap

Idea:
prefix sum

Time complexity: O(n)
Space complexity: O(n)

"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not nums or len(nums) == 0:
            return 0

        # key: prefix sum
        # value: frequency
        prefix_sum = {}   # base case

        res = 0
        current_sum = 0
        for i in range(len(nums)):
            current_sum += nums[i]
            if current_sum == k:
                res += 1

            complement = current_sum - k
            if complement in prefix_sum.keys():
                res += prefix_sum[complement]

            prefix_sum[current_sum] = prefix_sum.get(current_sum, 0) + 1

        return res


if __name__ == "__main__":
    solu = Solution()
    print(solu.subarraySum([1, 1, 1], 2))   # expect 2
    print(solu.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))  # expect 1
    print(solu.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))   # expect 55
    print(solu.subarraySum([1, 2, 3], 3))   # expect 2
