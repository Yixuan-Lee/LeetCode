"""
Idea:
Choose the substrings cleverly using hash map

Input: "babad"
    hash map looks like:
    {
        'b': [0, 2]
        'a': [1, 3]
        'd': [4]
    }

If the length of the list of a character is larger than 1, then
there is an possibility to have a palindrome ended by the character

Once we have all the indices for characters appearing in the string,
then we can try the possibilities one by one.

Time complexity: O(n^3)
Space complexity: O(n)

"""

from collections import defaultdict

class Solution:
    def longestPalindrome(self, s: str) -> str:
        # boundary conditions:
        if not s or len(s) < 1:
            return ''

        # val to store the final rs
        rs = ''
        # dict to store the indexes of one character
        char_map = defaultdict(list)

        for index, char in enumerate(s):
            char_map[char].append(index)

        def check(input):
            return input == input[::-1]

        # check palindrome
        for char in char_map:
            if len(char_map[char]) < 2:
                continue
            cur_list = char_map[char]
            for i in range(len(cur_list)):
                for j in range(len(cur_list)-1,i,-1):
                    if j-i+1 > len(rs):
                        check(s[cur_list[i]:cur_list[j]+1])
                        rs = s[cur_list[i]:cur_list[j]+1]
        if rs == '':
            rs = s[0]
        return rs

