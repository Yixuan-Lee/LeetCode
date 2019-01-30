// references:
//      https://leetcode.com/articles/move-zeroes/


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroFoundAt++] = nums[i];
            }
        }
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {

    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [1, 3, 12, 0, 0]

    nums = vector<int> {0, 0, 0, 0, 0};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [0, 0, 0, 0, 0]

    nums = vector<int> {0, 0, 5, 0, 0, 6, 9, 0};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [5, 6, 9, 0, 0, 0, 0]

    nums = vector<int> {2, 1};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [2, 1]

    nums = vector<int> {0, 2};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [2, 1]

    nums = vector<int> {1, 0, 1};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [1, 1, 0]

    nums = vector<int> {4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    s.moveZeroes(nums);
    std::cout << nums << std::endl;      // [4, 2, 4, 3, 5, 1, 0, 0, 0, 0]

    return 0;
}
