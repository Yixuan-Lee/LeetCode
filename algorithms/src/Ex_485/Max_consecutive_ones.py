class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        max_ones = 0
        last_zero = -1 if nums[0] != 0 else 0
        nums.append(0)      # force the last item to be 0
        for i in range(len(nums)):
            if nums[i] == 0:
                max_ones = max(i - last_zero + 1 - 2, max_ones)
                last_zero = i
        return max_ones

if __name__ == '__main__':
    s = Solution()
    nums = [1, 1, 0, 1, 1, 1]
    print(s.findMaxConsecutiveOnes(nums))

    nums = [1, 0, 1, 1, 0, 1]
    print(s.findMaxConsecutiveOnes(nums))
