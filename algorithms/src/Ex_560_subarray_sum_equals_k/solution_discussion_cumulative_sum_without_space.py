"""
Reference:
https://leetcode.com/problems/subarray-sum-equals-k/solution/

Idea:
in the cumulative_sum approach, we store each cumulative sum in ssum, however, we
can find the sum for each subarray on the go while considering different end points.

Time complexity: O(n^2) [TLE]
Space compelxity: O(1)

"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        for start in range(len(nums)):
            sum_subarray = 0
            for end in range(start, len(nums)):
                sum_subarray += nums[end]   # compute the cumulative sum on the go
                if sum_subarray == k:
                    count += 1
        return count


if __name__ == '__main__':
    solu = Solution()
    print(solu.subarraySum([1, 1, 1], 2))   # expect 2
    print(solu.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))  # expect 1
    print(solu.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))   # expect 55
    print(solu.subarraySum([1, 2, 3], 3))   # expect 2
