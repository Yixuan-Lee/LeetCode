from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if not nums or len(nums) == 0:
            return 0

        res = 0
        for start in range(len(nums)):
            for end in range(start+1, len(nums)+1):
                if sum(nums[start:end]) == k:
                    res += 1
        return res


if __name__ == '__main__':
    solu = Solution()
    print(solu.subarraySum([1, 1, 1], 2))   # expect 2
    print(solu.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))  # expect 1
    print(solu.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))   # expect 55
    print(solu.subarraySum([1, 2, 3], 3))   # expect 2
