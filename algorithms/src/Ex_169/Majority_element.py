from typing import List


class Solution:
    # divide-and-conquer
    def majorityElement(self, nums: List[int]) -> int:
        return self.divideAndConquer(nums, 0, len(nums) - 1)

    def divideAndConquer(self, nums: List[int], lo, hi) -> int:
        if lo == hi:
            return nums[lo]
        mid = int((lo + hi) / 2)
        leftMajElem = self.divideAndConquer(nums, lo, mid)
        rightMajElem = self.divideAndConquer(nums, mid + 1, hi)

        if leftMajElem == rightMajElem:
            return leftMajElem
        else:
            leftMajElemCount = 0
            rightMajElemCount = 0
            for i in range(lo, hi + 1):
                if nums[i] == leftMajElem:
                    leftMajElemCount += 1
                elif nums[i] == rightMajElem:
                    rightMajElemCount += 1

            if leftMajElemCount > rightMajElemCount:
                return leftMajElem
            else:
                return rightMajElem


if __name__ == '__main__':
    s = Solution()
    nums = [int(x) for x in input().split(",")]
    ans = s.majorityElement(nums)
    print(ans)
