// references:
//      https://leetcode.com/submissions/detail/197764000/ (4ms sample submission)


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
        vector<int> dp(static_cast<unsigned long> (size), INT_MIN);
        int minPrice = INT_MAX;
        for (int i = 0; i < size; i++) {
            minPrice = std::min(minPrice, prices[i]);
            dp[i] = std::max(dp[i], prices[i] - minPrice);
        }
        int res = INT_MIN;
        for (const auto &i : dp) {
            res = std::max(res, i);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> input {7, 1, 5, 3, 6, 4};
//    vector<int> input {7, 6, 4, 3, 1};
    std::cout << s.maxProfit(input) << std::endl;
    return 0;
}
