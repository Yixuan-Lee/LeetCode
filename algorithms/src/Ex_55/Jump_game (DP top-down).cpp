// references:
//      https://leetcode.com/articles/jump-game/   (great article)

// dynamic programming top-down:
//      time  complexity: O(n^2)
//      space complexity: O(2n) = O(n)


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
        memo = new Index[size];
        // initializes the memo table
        for (int i = 0; i < size; i++) {
            memo[i] = Index::UNKNOWN;
        }
        memo[size - 1] = Index::GOOD;   // last index can reach itself

        return canJumpFromPosition(0, nums);
    }

    ~Solution() {
//        std::cout << "entering the destructor" << std::endl;
        delete memo;
    }

private:
    enum Index {
        GOOD,
        BAD,
        UNKNOWN
    };

    Index *memo;

    bool canJumpFromPosition(int position, vector<int> nums) {
        if (*(memo + position) != Index::UNKNOWN) {
            return *(memo + position) == Index::GOOD ? true : false;
        }

        // perform the backtracking steps
        int furthestJumpTo = std::min(
                position + nums[position],
                static_cast<int> (nums.size() - 1));
        for (int nextPosition = furthestJumpTo;
             nextPosition >= position + 1; nextPosition--) {
            if (canJumpFromPosition(nextPosition, nums)) {
                *(memo + position) = Index::GOOD;
                return true;
            }
        }

        *(memo + position) = Index::BAD;
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums {2, 4, 2, 1, 0, 2, 0};
    std::cout << s.canJump(nums) << std::endl;
    return 0;
}
