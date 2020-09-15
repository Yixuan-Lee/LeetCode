"""
Time complexity: O(n)
Space complexity: O(n)

"""

from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # allocate left product array and right product array
        # left_product[i] is the product of elements of [0, i)
        # right_product[i] is the product of elements of (i, end]
        left_product = [1] * len(nums)
        right_product = [1] * len(nums)
        output = [0] * len(nums)

        # initialize and fill out the left_product
        left_product[0] = 1
        for i in range(1, len(nums)):
            left_product[i] = left_product[i-1] * nums[i-1]

        # initialize and fill out the right_product
        right_product[-1] = 1
        for i in range(len(nums) - 2, -1, -1):
            right_product[i] = right_product[i+1] * nums[i+1]

        # fill out the output
        for i in range(len(nums)):
            output[i] = left_product[i] * right_product[i]
        return output


if __name__ == "__main__":
    solu = Solution()
    print(solu.productExceptSelf([1,2,3,4]))    # expect [24,12,8,6]
