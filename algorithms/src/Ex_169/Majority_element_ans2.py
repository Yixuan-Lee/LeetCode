import math
from collections import Counter


class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # convert the array to counter
        c = Counter(nums)
        major_times = math.floor(len(nums) / 2)

        # most_common item [0] and its appearing time [1]
        most_common = c.most_common(int(major_times) + 1)[0]

        return most_common[0]


if __name__ == '__main__':
    s = Solution()
    nums = [3, 2, 3]
    print(s.majorityElement(nums))

    nums = [2, 2, 1, 1, 1, 2, 2]
    print(s.majorityElement(nums))
