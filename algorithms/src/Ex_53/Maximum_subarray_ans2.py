class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # initial
        curr_sum = nums[0]
        memo = [nums[0]]
        max_sum = nums[0]
        # traversal
        for i in range(1, len(nums)):
            # decide whether we open a new array from current item
            # or we keep adding
            memo.append(max(memo[i - 1] + nums[i], nums[i]))
            max_sum = max(max_sum, memo[i])

        return max_sum


if __name__ == '__main__':
    s = Solution()
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(s.maxSubArray(nums))
