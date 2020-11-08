"""
Reference:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

Idea:
based on the idea in solution_discussion_dynamic_program, we don't need to maintain
3 arrays, we can replace them by variables

Time complexity: O(n)
Space complexity: O(1)

"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        sold = 0
        hold = float('-inf')
        rest = 0
        for i in range(n):
            # if we buy at state time i
            hold = max(hold, rest - prices[i])
            # if we rest at state time i
            rest = max(rest, sold)
            # if we sell at state time i
            sold = hold + prices[i]
        return max(sold, rest)


if __name__ == '__main__':
    solu = Solution()
    print(solu.maxProfit([1, 2, 3, 0, 2]))
    print(solu.maxProfit([]))
    print(solu.maxProfit([1, 2, 4]))
