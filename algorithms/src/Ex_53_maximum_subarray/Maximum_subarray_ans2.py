class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # initial
        memo = [nums[0]]    # memo records the maximum sum till each index
        max_sum = nums[0]
        max_arr = [nums[0]]
        # traversal
        for i in range(1, len(nums)):
            # decide whether we open a new array from current item
            # or we keep adding
            memo.append(max(memo[i - 1] + nums[i], nums[i]))
            new_max_sum = max(max_sum, memo[i])

            # keep track of maximum array
            if max(memo[i - 1] + nums[i], nums[i]) == memo[i - 1] + nums[i]:
                # keep adding current item
                if new_max_sum == max_sum:
                    # update max array
                    max_arr.append(nums[i])
            elif max(memo[i - 1] + nums[i], nums[i]) == nums[i]:
                # open a new array from current item
                max_arr = [nums[i]]

            max_sum = new_max_sum

        print(max_arr)
        return max_sum


if __name__ == '__main__':
    s = Solution()
    print(s.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
