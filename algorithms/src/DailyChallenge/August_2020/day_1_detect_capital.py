class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        all_capitals = False
        all_non_capitals = False
        only_first_capital = True

        if len(word) == 1:
            return True

        if word[0].isupper():
            all_capitals = True
            only_first_capital = True
            all_non_capitals = False

        for i in range(1, len(word)):
            if word[i].islower():
                all_capitals = False
            elif word[i].isupper():
                all_non_capitals = False
                only_first_capital = False

        return all_capitals or all_non_capitals or only_first_capital


if __name__ == '__main__':
    s = Solution()
    word = "initial"

    while len(word) != 0:
        word = str(input())
        if len(word) == 0:
            break
        print(s.detectCapitalUse(word))
