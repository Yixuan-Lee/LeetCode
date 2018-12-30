// references:
//      https://leetcode.com/articles/jump-game/   (great article)

// backtracking:
//      time  complexity: O(2^n)
//      space complexity: O(n)


#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        if (nums.empty()) {
            return false;
        }

        return canJumpFromPosition(0, nums);
    }

private:
    bool canJumpFromPosition(int position, vector<int> nums) {
        if (position == nums.size() - 1) {
            return true;
        }

        // calculates the furthest position that I can jump to at this position
        int furthestJumpTo = std::min(
                position + nums[position],
                static_cast<int> (nums.size() - 1));

        // tries every single jump pattern
        // optimizes the for loop. Try to make the biggest jump
        // (old version)
//        for (int nextPosition = position + 1;
//             nextPosition <= furthestJumpTo; nextPosition++) {
//            if (canJumpFromPosition(nextPosition, nums)) {
//                return true;
//            }
//        }
        // (new version)
        for (int nextPosition = furthestJumpTo;
             nextPosition >= position + 1; nextPosition--) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
//    vector<int> arr {2, 3, 1, 1, 4};
    vector<int> arr {3, 2, 1, 0, 4};
    std::cout << s.canJump(arr) << std::endl;
    return 0;
}
