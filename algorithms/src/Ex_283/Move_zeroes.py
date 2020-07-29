class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        next_idx = 0
        # fill the non-zero numbers
        for i in range(len(nums)):
            if nums[i] | 0 != 0:
                nums[next_idx] = nums[i]
                next_idx += 1
        # fill the zeros at the end
        for i in range(next_idx, len(nums)):
            nums[i] = 0

        return nums


if __name__ == '__main__':
    s = Solution()
    nums = [0, 1, 0, 3, 12]
    print(s.moveZeroes(nums))
