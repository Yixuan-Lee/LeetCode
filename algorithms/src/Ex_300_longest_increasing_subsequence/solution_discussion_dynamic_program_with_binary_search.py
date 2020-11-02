"""
Reference:
https://leetcode.com/problems/longest-increasing-subsequence/discuss/152065/Python-explain-the-O(nlogn)-solution-step-by-step
https://leetcode.com/problems/longest-increasing-subsequence/solution/  (and solution comments from @simpleAndElegant and @georgehuang_net)
https://www.youtube.com/watch?v=22s1xxRvy28

Idea:
patience sort
dp[i] stores the increasing sub-sequence including and until nums[i]
while traversing nums, we keep on filling the dp array with the elements encountered so far.
since dp array is storing increasing sub-sequence, binary search is used to insert nums[i] at the correct position.

note that dp array does not result in longest increasing sub-sequence, but we keep recording its length to get
the longest LIS.

more explanation from @georgehuang_net:
It needs to explain the meaning of dp array : it is not necessary the current longest sequence, but the sequence that could be used to deduct the len of the longest sequence

In regular DP solution, for every incoming nums[i] , it needs to match against every dp[j] (where j<i）
because each of those dp[j] (where j<i）is possible candidate for new LIS

The smartness behind this DP solution is to remember the one and only one sequence that is capable to produce LIS in the dp array, and that sequence maintain the same len as the LIS

For example [10,9,2,5,7,3,5,8]
1: num[0]=10, dp = [10]
2: num[1]= 9, dp= [9] 9 <10, replace 10 with 9, [9] will be able to produce longer LIS than [10]
3 num[2]= 2, dp = [2] 2 < 9, replace 9 with 2, [2] will be able to produce longer LIS than [9]
4 num[3]= 5, dp = [2, 5] append 5, [2, 5] will be the candidate to produce longer LIS
5 num[4]= 7, dp = [2, 5, 7] append 7, [2, 5, 7] will be the candidate to produce longer LIS
6 num[5]= 3, dp = [2, 3, 7] 3<5 , replace 5 with 3, [2, 3, 7] will be the candidate to produce longer LIS
[2,3,7] is not a valid sequence, but a candidate for [2,3,5] to be developed
If nums stop at [10,9,2,5,7,3,5], we still get correct LIS (dp.len==3)
7 num[6]= 5, dp = [2, 3, 5] 5<7 , replace 7 with 5, [2, 3, 5] will be the candidate to produce longer LIS
8 num[7]= 8, dp = [2, 3, 5, 8] append 8, [2, 3,5,8] will be the candidate to produce longer LIS

Time complexity: O(nlogn)
Space complexity: O(n)

"""

from typing import List


class Solution:
    # O(n*m) solution
    # def lengthOfLIS(self, nums: List[int]) -> int:
    #     sub = []
    #     for num in nums:
    #         pos, sub_len = 0, len(sub)
    #         while pos <= sub_len:   # update the element to the correct position
    #             if pos == sub_len:
    #                 sub.append(num)
    #                 break
    #             elif num <= sub[pos]:
    #                 sub[pos] = num
    #                 break
    #             else:
    #                 pos += 1
    #     return len(sub)

    # since sub is incremental, we can use a binary search to find the correct insertion position
    # binary search with O(nlogn) solution
    def lengthOfLIS(self, nums: List[int]) -> int:
        def binary_search(sub, trg):
            lo, hi = 0, len(sub) - 1
            while lo <= hi:
                mid = lo + (hi - lo) // 2
                if sub[mid] < trg:
                    lo = mid + 1
                elif sub[mid] > trg:
                    hi = mid - 1
                elif sub[mid] == trg:
                    return mid
            return lo

        sub = []
        for num in nums:
            pos = binary_search(sub, num)
            if pos == len(sub):
                sub.append(num)
            else:
                sub[pos] = num  # replace the value
        return len(sub)

    # more optimized pythonic
    # def lengthOfLIS(self, nums: List[int]) -> int:
    #     piles = [] # store the smallest number of each pile
    #     for num in nums:
    #         dest_pile = bisect.bisect_left(piles, num)
    #         if dest_pile == len(piles):
    #             piles.append(num)
    #         else:
    #             piles[dest_pile] = num
    #     return len(piles)


if __name__ == '__main__':
    solu = Solution()
    print(solu.lengthOfLIS([0, 8, 4, 12, 2]))   # 3
    print(solu.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18]))   # 4
    print(solu.lengthOfLIS([4, 10, 4, 3, 8, 9])) # 3
