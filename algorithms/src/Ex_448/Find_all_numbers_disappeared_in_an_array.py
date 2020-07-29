from typing import List


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        # make the nums[index] negative for index in nums
        # the positive indices correspond to the disappeared values
        for i in range(len(nums)):
            index = abs(nums[i]) - 1
            nums[index] = -abs(nums[index])
        return [i + 1 for (i, num) in enumerate(nums) if num > 0]


if __name__ == '__main__':
    s = Solution()
    nums = [int(x) for x in input().split(',')]
    # for (i, num) in enumerate(nums):
    #     print(i, " ", num)
    ans = s.findDisappearedNumbers(nums)
    print(ans)
