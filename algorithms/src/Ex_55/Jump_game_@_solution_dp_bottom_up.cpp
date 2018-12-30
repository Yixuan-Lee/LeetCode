// references:
//      https://leetcode.com/articles/jump-game/   (great article)

// dynamic programming bottom-up:
//      time  complexity: O(n^2)
//      space complexity: O(n)

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
        Index memo[size];
        // initializes the memo table
        for (int i = 0; i < size; i++) {
            memo[i] = Index::UNKNOWN;
        }
        memo[size - 1] = Index::GOOD;   // the last position can reach itself

        for (int i = size - 2; i >= 0; i--) {   // size - 2 is the second last
            int furthestJumpTo = std::min(
                    i + nums[i],
                    size - 1);
            for (int j = i + 1; j <= furthestJumpTo; j++) {
                if (memo[j] == Index::GOOD) {
                    memo[i] = Index::GOOD;
                    break;
                }
            }
        }

        return memo[0] == Index::GOOD;
    }

private:
    enum Index {
        GOOD,
        BAD,
        UNKNOWN
    };
};


int main() {
    Solution s;
//    vector<int> nums {2, 4, 2, 1, 0, 2, 0};
    vector<int> nums {1, 1, 0};
    std::cout << s.canJump(nums) << std::endl;
    return 0;
}
