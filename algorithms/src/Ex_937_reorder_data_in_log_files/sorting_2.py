"""
reference:
https://leetcode.com/problems/reorder-data-in-log-files/discuss/198197/simple-Python3-solution-beats-99

Time complexity: O(nlogn)
Space complexity: O(n)

"""

from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        letter_logs = []
        digit_logs = []

        for string in logs:
            if string.split(' ')[1].isnumeric():
                digit_logs.append(string)
            else:
                letter_logs.append(string)

        # print(letter_logs)
        # print(digit_logs)

        # sort letter_logs
        letter_logs = sorted(letter_logs, key=lambda x: x.split(' ')[0])
        letter_logs = sorted(letter_logs, key=lambda x: x.split(' ')[1:])
        # print(letter_logs)

        return letter_logs + digit_logs


if __name__ == '__main__':
    solu = Solution()
    # expect: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
    print(solu.reorderLogFiles(["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]))
