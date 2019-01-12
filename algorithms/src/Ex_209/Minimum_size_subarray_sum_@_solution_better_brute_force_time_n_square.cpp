// references:
//      https://leetcode.com/articles/minimum-size-subarray-sum/


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        auto n = static_cast<int> (nums.size());
        if (n == 0) {
            return 0;
        }

        int ans = INT_MAX;
        // stores the sum from the beginning
        vector<int> sums(static_cast<unsigned long> (n));
        sums[0] = nums[0];
        for (int i = 1; i < n; i++) {
            sums[i] = sums[i - 1] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // sum of nums[i...j]
                int sum = sums[j] - sums[i] + nums[i];
                if (sum >= s) {
                    // found the smallest subarray (from i to j) with sum >= s
                    ans = std::min(ans, j - i + 1);
                    break;
                }
            }
        }

        return (ans != INT_MAX) ? ans : 0;
    }
};


int main() {
    Solution s;
    vector<int> nums;
    int target;

    nums = vector<int> {2, 3, 1, 2, 4, 3};
    target = 7;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 2

    nums = vector<int> {1, 2, 3, 4, 5};
    target = 15;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 5

    nums = vector<int> {1, 1};
    target = 3;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 0

    return 0;
}
