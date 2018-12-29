// references:
//      https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        auto size = static_cast<int> (prices.size());
        int minPrice = INT32_MAX;   // records the minimum price
        int maxProfit = 0;          // records the maximum profit
        for (int i = 0; i < size; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};


int main() {
    Solution s;
//    vector<int> input {7, 1, 5, 3, 6, 4};
    vector<int> input {7, 6, 4, 3, 1};
    std::cout << s.maxProfit(input) << std::endl;
    return 0;
}
