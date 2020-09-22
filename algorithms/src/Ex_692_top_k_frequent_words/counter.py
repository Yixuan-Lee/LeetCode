from collections import Counter
from typing import List


class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        words = sorted(words)   # sort the list alphabetical
        c = Counter(words)
        return [key for key, _ in c.most_common(k)]

if __name__ == '__main__':
    solu = Solution()
    print(solu.topKFrequent(["i", "love", "leetcode", "i", "love", "coding"], 2))
    print(solu.topKFrequent(["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], 4))
    print(solu.topKFrequent(["i", "love", "leetcode", "i", "love", "coding"], 3))
