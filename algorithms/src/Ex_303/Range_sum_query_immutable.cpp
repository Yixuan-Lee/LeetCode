#include <iostream>
#include <vector>

using std::vector;

class NumArray {
public:
    explicit NumArray(vector<int> nums) {
        if (nums.empty()) {
            return;
        }

        sums = vector<int>(nums.size(), 0);
        sums[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (sums.empty() || i < 0 || j < 0 || i > j) {
            return 0;
        }
        if (i == 0) {
            return sums[j];
        } else {
            return sums[j] - sums[i - 1];
        }
    }

private:
    // sums[i] means sum of nums[0...i]
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */


int main() {
    NumArray obj(vector<int> {-2, 0, 3, -5, 2, -1});

    std::cout << obj.sumRange(0, 2) << std::endl;   // 1

    std::cout << obj.sumRange(2, 5) << std::endl;   // -1

    std::cout << obj.sumRange(0, 5) << std::endl;   // -3


    obj = NumArray(vector<int> {});

    std::cout << obj.sumRange(0, 2) << std::endl;   // 0

    return 0;
}
