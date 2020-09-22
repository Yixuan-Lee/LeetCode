"""
Idea:
optimized brute force

Time complexity: O(n^2)
Space compelxity: O(n^2)
"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not nums or len(nums) == 0:
            return 0

        # key: (start index, end index)
        # value: summation between [start index, end index)
        sum = {(0, 0): 0}   # base case

        # fill sum[(0, i)]
        for i in range(1, len(nums) + 1):
            sum[(0, i)] = sum[(0, i-1)] + nums[i-1]

        # fill sum[(i, j)]
        res = 0
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums) + 1):
                sum[(i, j)] = sum[(0, j)] - sum[(0, i)]
                if sum[(i, j)] == k:
                    res += 1

        # print(sum)

        return res



if __name__ == "__main__":
    solu = Solution()
    print(solu.subarraySum([1, 1, 1], 2))   # expect 2
    print(solu.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))  # expect 1
    print(solu.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))   # expect 55
    print(solu.subarraySum([1, 2, 3], 3))   # expect 2
