from typing import List
import copy
import sys


class Solution:
    # solution 1:
    # def thirdMax(self, nums: List[int]) -> int:
    #     temp = copy.deepcopy(nums)
    #     max = 0
    #     for j in range(0, 3):
    #         if len(temp) == 0:
    #             return max
    #         for i in range(1, len(temp)):
    #             if temp[i] > temp[0]:
    #                 temp[i], temp[0] = temp[0], temp[i]
    #
    #         if j == 0:
    #             max = temp[0]
    #         if j < 2:
    #             temp = [x for x in temp if x != temp[0]]
    #     return temp[0]

    # solution 2:
    def thirdMax(self, nums: List[int]) -> int:
        m = [-sys.maxsize - 1, -sys.maxsize - 1, -sys.maxsize - 1]
        for num in nums:
            if num not in m and num > m[0]:
                m = [num, m[0], m[1]]
            elif num not in m and num > m[1]:
                m = [m[0], num, m[1]]
            elif num not in m and num > m[2]:
                m = [m[0], m[1], num]
        return m[2] if (-sys.maxsize - 1) not in m else max(nums)


if __name__ == '__main__':
    s = Solution()
    nums = [int(x) for x in input().split(", ")]
    ans = s.thirdMax(nums)
    print(ans)
