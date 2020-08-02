from collections import Counter

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        c = Counter(s)
        for idx, ch in enumerate(s):
            if c[ch] == 1:
                return idx
        return -1


if __name__ == '__main__':
    s = Solution()
    word = 'initial'

    while len(word) != 0:
        word = str(input())
        if len(word) == 0:
            break
        print(s.firstUniqChar(word))
