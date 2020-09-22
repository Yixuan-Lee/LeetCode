from typing import List
from typing import Dict


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        alien_dict: Dict[str, int] = dict()
        index = 0
        for ch in order:
            alien_dict[ch] = index
            index += 1

        for i in range(1, len(words)):
            prev = words[i - 1]
            curr = words[i]
            if not self.lower_than(prev, curr, alien_dict):
                return False

        return True

    def lower_than(self, word1: str, word2: str, alien_dict: Dict[str, int]) -> bool:
        """
        check if word1 < word2
        :param word1:
        :param word2:
        :return:
        """
        length_w1 = len(word1)
        length_w2 = len(word2)

        for i in range(min(length_w1, length_w2)):
            if alien_dict.get(word1[i]) < alien_dict.get(word2[i]):
                return True
            elif alien_dict.get(word1[i]) > alien_dict.get(word2[i]):
                return False

        return length_w1 <= length_w2


if __name__ == '__main__':
    solu = Solution()
    print(solu.isAlienSorted(["hello","leetcode"], "hlabcdefgijkmnopqrstuvwxyz"))   # expect True
    print(solu.isAlienSorted(["word","world","row"], "worldabcefghijkmnpqstuvxyz")) # expect False
