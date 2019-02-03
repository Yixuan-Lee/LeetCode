#include <iostream>
#include <vector>

using std::vector;

class NumArray {
public:
    explicit NumArray(vector<int> nums) {
        if (nums.empty()) {
            return;
        }

        this->nums = nums;
        sums = vector<int>(nums.size(), 0);
        sums[0] = nums[0];
        for (int i = 1; i < sums.size(); i++) {
            sums[i] = sums[i - 1] + nums[i];
        }
    }

    void update(int i, int val) {
        int diff = val - this->nums[i];
        this->updateSums(i, diff);
        this->nums[i] = val;
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sums[j];
        }

        return sums[j] - sums[i - 1];
    }

private:
    vector<int> sums;
    vector<int> nums;

    void updateSums(int idx, int diff) {
        for (int i = idx; i < sums.size(); i++) {
            sums[i] += diff;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */


int main() {
    NumArray obj(vector<int> {1, 3, 5});
    std::cout << obj.sumRange(0, 2) << std::endl;   // 9
    obj.update(1, 2);
    std::cout << obj.sumRange(0, 2) << std::endl;   // 8

    obj = NumArray(vector<int> {7, 2, 7, 2, 0});
    obj.update(4, 6);
    obj.update(0, 2);
    obj.update(0, 9);
    std::cout << obj.sumRange(4, 4) << std::endl;   // 6
    obj.update(3, 8);
    std::cout << obj.sumRange(0, 4) << std::endl;   // 27
    obj.update(4, 1);
    std::cout << obj.sumRange(0, 3) << std::endl;   // 21
    std::cout << obj.sumRange(0, 4) << std::endl;   // 28
    obj.update(0, 4);

    return 0;
}
