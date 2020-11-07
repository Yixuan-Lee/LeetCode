"""
Reference:
https://leetcode.com/problems/subsets/solution/
https://www-cs-faculty.stanford.edu/~knuth/taocp.html
https://en.wikipedia.org/wiki/Padding_(cryptography)#Zero_padding

Idea:
map each subset to a bitmask of length n, where 1 on the i-th position in bitmask
means the presence of nums[i] in the subset, and 0 means its absence.

for example:
for the subset [1, 3], the bitmask is [1, 0, 1]
for the subset [2, 3], the bitmask is [0, 1, 1]
etc.

so our task is to generate n bitmasks from [0, 0, 0] to [1, 1, 1] for the test case [1, 2, 3]


Time complexity: O(n * 2^n)
Space complexity: O(n * 2^n)

"""

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        nth_bit = 1 << n
        for i in range(2**n):
            # generate bitmask, from 0.00 to 1.11, by using stanard bit manipulation trick
            # bin() is an in-built function in Python that takes in integer x and returns the binary representation of x in a string format.
            bitmask = bin(i | nth_bit)[3:]
            # append subset corresponding to that bitmask
            res.append([nums[j] for j in range(n) if bitmask[j] == '1'])
        return res


if __name__ == '__main__':
    solu = Solution()
    print(solu.subsets([1, 2, 3]))
