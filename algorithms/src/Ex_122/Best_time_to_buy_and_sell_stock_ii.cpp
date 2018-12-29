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
        int profit = 0;
        int buyPrice = 0;
        int sellPrice = 0;
        for (int i = 0; i < size - 1; i++) {
            if (prices[i] >= prices[i + 1]) {
                // if next day's price is slower, then don't buy in
                continue;
            }
            buyPrice = prices[i];
            int j;
            for (j = i + 1;
                 j < size - 1 && prices[j] <= prices[j + 1]; j++) {}
            sellPrice = prices[j];
            profit += (sellPrice - buyPrice);
            i = j;
        }
        return profit;
    }
};


int main() {
    Solution s;
//    vector<int> input {7, 1, 5, 3, 6, 4};
//    vector<int> input {1, 2, 3, 4, 5};
//    vector<int> input {7, 6, 4, 3, 1};
//    vector<int> input {7, 1, 5, 3, 6, 4, 5};
    vector<int> input {1, 1};
    std::cout << s.maxProfit(input) << std::endl;
    return 0;
}