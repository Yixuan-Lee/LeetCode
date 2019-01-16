#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        auto size = static_cast<int> (nums.size());
        if (size == 1) {
            return nums[0];
        }
        if (size == 2) {
            return std::max(nums[0], nums[1]);
        }

        vector<int> dp;
        int maxVal_0toSizeMinus1;
        int maxVal_1toSize;

        dp.push_back(nums[0]);
        dp.push_back(std::max(nums[0], nums[1]));
        for (int i = 2; i < size - 1; i++) {
            dp.push_back(std::max(dp[i - 2] + nums[i], dp[i - 1]));
        }
        maxVal_0toSizeMinus1 = dp[size - 2];

        dp.clear();
        dp.push_back(0);
        dp.push_back(nums[1]);
        for (int i = 2; i < size; i++) {
            dp.push_back(std::max(dp[i - 2] + nums[i], dp[i - 1]));
        }
        maxVal_1toSize = dp[size - 1];

        return std::max(maxVal_0toSizeMinus1, maxVal_1toSize);
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {2, 3, 2};
    std::cout << s.rob(input) << std::endl;     // 3

    input = vector<int> {1, 2, 3, 2};
    std::cout << s.rob(input) << std::endl;     // 4

    input = vector<int> {2, 1, 1, 2};
    std::cout << s.rob(input) << std::endl;     // 3

    return 0;
}
