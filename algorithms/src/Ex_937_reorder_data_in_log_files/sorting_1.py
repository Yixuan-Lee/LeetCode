"""
reference:
https://leetcode.com/problems/reorder-data-in-log-files/discuss/352878/Python3-Sort-the-list-use-key

Time complexity:
Space complexity: O(1)

"""

from typing import List
from typing import Tuple


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def sort(logs: str) -> Tuple[str]:
            id, items = logs.split(' ', 1)
            if items[0].isnumeric():
                return (1, None, None)
            else:
                # 0: letter-logs comes before digit-logs
                # items: first, sort letters lexicongraphically
                # id: if ties, sort identifiers
                return (0, items, id)
        return sorted(logs, key=sort)


if __name__ == '__main__':
    solu = Solution()
    # expect: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
    print(solu.reorderLogFiles(["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]))
