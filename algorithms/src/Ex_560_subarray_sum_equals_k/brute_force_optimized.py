from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        if len(nums) == 0:
            return 0

        cnt = 0
        summation = [0] * (len(nums) + 1)
        summation[0] = 0
        for i in range(1, len(nums)+1):
            summation[i] = summation[i-1] + nums[i-1]
        for start in range(len(nums)):
            for end in range(start+1, len(nums)+1):
                if summation[end] - summation[start] == k:
                    cnt += 1
        return cnt


if __name__ == "__main__":
    solu = Solution()
    print(solu.subarraySum([1, 1, 1], 2))   # expect 2
    print(solu.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))  # expect 1
    print(solu.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))   # expect 55

