class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0

        left_lowest_price = [0] * len(prices)
        max_profit = [0] * len(prices)

        # initial
        left_lowest_price[0] = prices[0]
        max_profit[0] = 0

        for i in range(1, len(prices)):
            if prices[i] < left_lowest_price[i - 1]:
                left_lowest_price[i] = prices[i]
                max_profit[i] = max_profit[i - 1]
            else:
                left_lowest_price[i] = left_lowest_price[i - 1]
                max_profit[i] = max(prices[i] - left_lowest_price[i],
                                    max_profit[i - 1])
        return max_profit[-1]


if __name__ == '__main__':
    s = Solution()
    prices = [7, 1, 5, 3, 6, 4]
    print(s.maxProfit(prices))

    prices = [7, 6, 4, 3, 1]
    print(s.maxProfit(prices))

    prices = [2, 4, 1]
    print(s.maxProfit(prices))
