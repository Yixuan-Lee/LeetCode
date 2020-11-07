"""
Reference:
https://leetcode.com/problems/subarray-sum-equals-k/solution/

Idea:
in the brute force approach, we can figure out that there are (end-start) overlapped elements
between two indices, but we repeatedly compute the sum of overlapped elements.
thus we can make use of a cumulative sum array called ssum,
    ssum[i] = Σ_{j=0}^{i-1} {nums[j]}
base case:
    ssum[0] = 0
then in order to calculate the sum of elements laying between [start, end], we can
subtract the cumulative sum corresponding the two indices to obtain the sum of elements nums[start...end]

Time complexity: O(n^2) [TLE]
Space compelxity: O(n)

"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        # fill in the cumulative sum array
        ssum = [0] * (len(nums)+1)
        for i in range(1, len(nums)+1):
            ssum[i] = ssum[i-1] + nums[i-1]
        # count how many sum of subarray is equal to k
        for start in range(len(nums)):
            for end in range(start+1, len(nums)+1):
                sum_subarray = ssum[end] - ssum[start]
                if sum_subarray == k:
                    count += 1
        return count


if __name__ == '__main__':
    solu = Solution()
    print(solu.subarraySum([1, 1, 1], 2))   # expect 2
    print(solu.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))  # expect 1
    print(solu.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))   # expect 55
    print(solu.subarraySum([1, 2, 3], 3))   # expect 2
