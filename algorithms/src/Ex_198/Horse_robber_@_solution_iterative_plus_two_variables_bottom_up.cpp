// references:
//      https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.  (great article)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        // prev1 and prev2 optimize the memo array in Horse_robber_@_solution_iterative_plus_memo_bottom_up.cpp
        int prev1 = 0;      // store the maximum value of the first (i) horses
        int prev2 = 0;      // store the maximum value of the first (i - 1) horses
        for (const int &num : nums) {
            int temp = prev1;
            // prev2 + num: maximum value of the first (i - 1) horses + value of the horse i
            prev1 = std::max(prev2 + num, prev1);
            prev2 = temp;
        }
        return prev1;
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
