from typing import List
from collections import Counter

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        c = Counter(nums)
        return c.most_common()[0][0]

if __name__ == "__main__":
    solu = Solution()
    print(solu.findDuplicate([1,3,4,2,2]))  # expect 2
    print(solu.findDuplicate([3,1,3,4,2]))  # expect 3
