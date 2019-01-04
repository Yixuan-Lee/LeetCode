// references:
//      https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.  (great article)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        // initialize the memo with all -1
        memo = vector<int>(static_cast<unsigned long> (size), -1);

        return rob(nums, size - 1);
    }

private:
    vector<int> memo;

    int rob(const vector<int> &nums, int i) {
        if (i < 0) {
            return 0;
        }
        if (memo[i] >= 0) {
            // if we have calculated the value of position i, return directly
            return memo[i];
        }
        // if not, we calculate the value and memorize it
        memo[i] = std::max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
        return memo[i];
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
