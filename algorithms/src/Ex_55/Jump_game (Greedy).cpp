// references:
//      https://leetcode.com/articles/jump-game/   (great article)

// greedy:
//      time  complexity: O(n)
//      space complexity: O(1)

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.empty()) {
            return false;
        }

        auto size = static_cast<int> (nums.size());
        int leftMostGoodIndex = size - 1;
        for (int i = size - 1; i >= 0; i--) {
            if (i + nums[i] >= leftMostGoodIndex) {
                leftMostGoodIndex = i;
            }
        }
        return leftMostGoodIndex == 0;
    }
};


int main() {
    Solution s;
    vector<int> nums {9, 4, 2, 1, 0, 2, 0};
    std::cout << s.canJump(nums) << std::endl;
    return 0;
}
