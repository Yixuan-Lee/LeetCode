"""
Reference:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

Idea:
from the perspective of state machine, there are 3 states according to the action we can take at each time:
    s0: can rest or buy a stock
    s1: can rest or sell a stock
    s2: can rest and cannot buy/sell a stock
         <--
        /   \    rest
  rest |    s0 <----- s2
       \   /  \      ^
        -->    \    / sell
            buy \ /
                s1
              /   \
              \   /
               -->
               rest
at a state time i,
    * if we are at state s0, then s0[i] = max(s0[i-1], s2[i-1])
                                         s0[i-1]: at i-1 state time, we rest at s0
                                         s2[i-1]: at i-1 state time, we rest at s2
    * if we are at state s1, then s1[i] = max(s1[i-1], s0[i-1]-prices[i])
                                         s1[i-1]: at i-1 state time, we rest at s1
                                         s0[i-1]: at i-1 state time, we buy a stock at s0
    * if we are at state s2, then s2[i] = s1[i-1] + prices[i]
                                         s1[i-1]: prices at state time i-1
                                         prices[i]: sell a stock at state time i
base cases:
    * s0[0] = 0
    * s1[0] = -prices[0]
    * s2[0] = -INFINITY

since our goal is to maximize the profit, so at the last state time, we cannot be at state s1,
meaning it is impossible that we take 'buy' action as the last action
so the maximum profit should be `max(s0[n], s2[n])`

Time complexity: O(n)
Space compelxity: O(n)

"""

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        if n == 0 or n == 1:
            return 0
        s0, s1, s2 = [0] * n, [0] * n, [0] * n
        # set base cases
        s0[0] = 0
        s1[0] = -prices[0]
        s2[0] = float('-inf')
        # fill the 3 arrays
        for i in range(1, n):
            s0[i] = max(s0[i-1], s2[i-1])   # max profit if we rest at state time i
            s1[i] = max(s1[i-1], s0[i-1]-prices[i]) # max profit if we buy at state time i
            s2[i] = s1[i-1] + prices[i]     # max profit if we sell at state time i
        return max(s0[-1], s2[-1])


if __name__ == '__main__':
    solu = Solution()
    print(solu.maxProfit([1, 2, 3, 0, 2]))
    print(solu.maxProfit([1, 2, 4]))
