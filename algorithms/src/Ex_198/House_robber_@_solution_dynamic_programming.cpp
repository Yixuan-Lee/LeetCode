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

        // dp[i] means that the maximum money I can rob before position i
        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(std::max(nums[0], nums[1]));
        for (int i = 2; i < size; i++) {
            dp.push_back(std::max(dp[i - 2] + nums[i], dp[i - 1]));
        }

        return dp[size - 1];
    }
};


int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {1, 2, 3, 1};
    std::cout << s.rob(nums) << std::endl;      // 4

    nums = vector<int> {2, 7, 9, 3, 1};
    std::cout << s.rob(nums) << std::endl;      // 12

    nums = vector<int> {2, 1, 1, 2};
    std::cout << s.rob(nums) << std::endl;      // 4

    nums = vector<int> {2, 1, 3, 10, 2};
    std::cout << s.rob(nums) << std::endl;      // 12

    nums = vector<int> {2, 6, 3};
    std::cout << s.rob(nums) << std::endl;      // 6

    nums = vector<int> {1, 7, 9, 4};
    std::cout << s.rob(nums) << std::endl;      // 11

    return 0;
}
