"""
Reference:
https://leetcode.com/problems/subarray-sum-equals-k/solution/

Idea:
in the cumulative_sum approach, we've know that
    ssum[i] = Σ_{j=0}^{i-1} {nums[j]}
base case:
    ssum[0] = 0

based on these thoughts, we can make use of a hashmap called mmap to store the
cumulative sum upto all the possible indices, i.e. [0, length-1], with the number
of times the sum of subarray occurs.
    mmap:   key: sum of subarray starting from index 0
            value: number of occurrence of this sum
every time we encouter a new sum, we insert a new entry in the mmap.
if the same sum occurs again, we increment the counter, i.e. value, corresponding to that sum

as we traverse over the nums, we also determine the number of times that the sum (ssum-k) has occured in mmap,
since it will determine whether there is a subarray which sum up to k upto the current index.

Time complexity: O(n)
Space compelxity: O(n)

"""

from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mmap = {0: 1}   # base case
        ssum = 0
        count = 0
        for num in nums:
            ssum += num
            if ssum-k in mmap:
                count += mmap[ssum-k]
            mmap[ssum] = mmap.get(ssum, 0) + 1  # update hashmap
        return count


if __name__ == '__main__':
    solu = Solution()
    print(solu.subarraySum([3, 4, 7, 2, -3, 1, 4, 2], 7))   # 4
    print(solu.subarraySum([1, 1, 1], 2))   # expect 2
    print(solu.subarraySum([28, 54, 7, -70, 22, 65, -6], 100))  # expect 1
    print(solu.subarraySum([0, 0, 0, 0, 0, 0, 0, 0, 0, 0], 0))   # expect 55
    print(solu.subarraySum([1, 2, 3], 3))   # expect 2
