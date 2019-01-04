// references:
//      https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.  (great article)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        if (size == 0) {
            return 0;
        }
        vector<int> memo;
        memo.reserve(nums.size() + 1);
        memo[0] = 0;        // maximum value of first 0 horse is 0
        memo[1] = nums[0];  // maximum value of first 1 horse is nums[0]
        for (int i = 1; i < size; i++) {
            // memo[i]: maximum value of the first i horses
            // memo[i - 1] + nums[i]: maximum value of the first i - 1 horses + money of horse i
            memo[i + 1] = std::max(memo[i], memo[i - 1] + nums[i]);
        }
        return memo[size];
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
