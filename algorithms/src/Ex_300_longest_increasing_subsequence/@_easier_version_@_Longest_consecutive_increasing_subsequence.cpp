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

        int maxIncreasing = 1;
        int per = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) {
                per++;
            } else {
                if (per > maxIncreasing) {
                    maxIncreasing = per;
                }
                per = 1;
            }
        }

        return maxIncreasing;
    }
};


int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {10, 9, 2, 3, 7, 101, 18};
    std::cout << s.lengthOfLIS(nums) << std::endl;

    return 0;
}
