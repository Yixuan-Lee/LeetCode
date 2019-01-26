#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        int seq32 = 0;
        for (int i = 0; i <= size; i++) {
            seq32 ^= i;
        }
        for (auto &i : nums) {
            seq32 ^= i;
        }

        return seq32;
    }
};


int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {3, 0, 1};
    std::cout << s.missingNumber(nums) << std::endl;    // 2

    nums = vector<int> {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << s.missingNumber(nums) << std::endl;    // 8

    return 0;
}
