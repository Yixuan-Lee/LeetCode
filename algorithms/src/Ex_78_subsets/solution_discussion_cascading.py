"""
Reference:
https://leetcode.com/problems/subsets/solution/

Idea:
start from an empty subset in output list, then at each step, one takes an new
integer into consideration and generates new subsets from the existing ones.

Time complexity: O(n * 2^n)
Space complexity: O(n * 2^n)

"""

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        output = [[]]
        for num in nums:
            output += [curr + [num] for curr in output]
        return output


if __name__ == '__main__':
    solu = Solution()
    print(solu.subsets([1, 2, 3]))


