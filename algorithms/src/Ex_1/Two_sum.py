class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = {}
        for i in range(len(nums)):
            complement = target - nums[i]
            if complement in m:
                return [m[complement], i]
            else:
                # key: number value
                # value: index
                m[nums[i]] = i
        return []


if __name__ == '__main__':
    s = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    print(s.twoSum(nums, target))
