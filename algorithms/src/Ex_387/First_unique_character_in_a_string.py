from collections import OrderedDict

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if length == 0:
            return -1
        record = OrderedDict()
        nonrepeat_index = -1     # record the non-repeating word index
        for i in range(length):
            if s[i] not in record:
                record[s[i]] = [i]
                if nonrepeat_index == -1:
                    nonrepeat_index = i
            else:
                record[s[i]].append(i)
                if record[s[i]][0] == nonrepeat_index:
                    # reset nonrepeat_index to the next non-repeating word
                    # index
                    new_idx_set = False
                    for idx, letter in enumerate(record):
                        if len(record[letter]) == 1:
                            nonrepeat_index = record[letter][0]
                            new_idx_set = True
                            break
                    if not new_idx_set:
                        nonrepeat_index = -1
        return nonrepeat_index



if __name__ == '__main__':
    s = Solution()
    word = 'initial'

    while len(word) != 0:
        word = str(input())
        if len(word) == 0:
            break
        print(s.firstUniqChar(word))

