// references:
//      https://leetcode.com/articles/longest-increasing-subsequence/


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        if (size == 0 || size == 1) {
            return size;
        }

        // dp[i] represents the length of longest increasing subsequence upto to ith element
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < size; i++) {
            int max = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    max = std::max(max, dp[j]);
                }
            }
            dp[i] = max + 1;
        }

        int ans = 0;
        for (auto &i : dp) {
            if (i > ans) {
                ans = i;
            }
        }

        return ans;
    }
};


int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << s.lengthOfLIS(nums) << std::endl;      // 4

    return 0;
}
