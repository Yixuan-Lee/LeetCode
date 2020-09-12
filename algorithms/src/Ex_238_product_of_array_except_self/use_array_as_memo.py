from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        if len(nums) == 2:
            return [nums[1], nums[0]]

        # in the left_memo, it records the products of numbers from [0, ..., curr)
        # in the right_memo, it records the products of numbers from (curr, ..., len(nums)-1]
        left_memo = [1] * len(nums)
        right_memo = [1] * len(nums)
        for i in range(1, len(nums)):
            left_memo[i] = left_memo[i-1] * nums[i-1]
        for i in range(len(nums)-2, -1, -1):
            right_memo[i] = right_memo[i+1] * nums[i+1]

        # calculate the products
        products = [1] * len(nums)
        for i in range(len(nums)):
            products[i] = left_memo[i] * right_memo[i]

        return products


if __name__ == "__main__":
    solu = Solution()
    print(solu.productExceptSelf([1,2,3,4]))    # expect [24,12,8,6]
