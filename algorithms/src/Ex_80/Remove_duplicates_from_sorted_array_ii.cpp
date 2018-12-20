#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        auto size = static_cast<int>(nums.size());
        int occur = 1;  // appearance times of current number
        int end = 0;    // last index in returned array
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[end]) {
                if (occur < 2) {
                    nums[++end] = nums[i];
                    occur++;
                } else {
                    // if a number appears more than twice, then try to find
                    // next different number
                    occur = 0;
                    int j;
                    for (j = i; j < size && nums[j] == nums[end]; j++);

                    // set j-1 is because at the end of for, i will be added 1
                    // so next time, nums[i] will be a different number
                    i = j - 1;
                }
            } else {
                nums[++end] = nums[i];
                occur = 1;
            }
        }

        return end + 1;
    }
};


int main() {
    Solution s;
//    vector<int> input {0, 0, 1, 1, 1, 1, 2, 3, 3};
    vector<int> input {1, 1, 1, 1, 1, 1};
    std::cout << s.removeDuplicates(input) << std::endl;
    return 0;
}