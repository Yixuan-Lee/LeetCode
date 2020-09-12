#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (binarySearch(nums, nums[i], 0, i - 1)
                || binarySearch(nums, nums[i], i + 1,
                        static_cast<int> (nums.size() - 1))) {
                return nums[i];
            }
        }
        return -1;
    }

private:
    bool binarySearch(const vector<int> &nums, int target, int lo, int hi) {
        if (lo < 0 || hi > nums.size() - 1 || lo > hi) {
            return false;
        }

        if (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] == target) {
                return true;
            }
            return binarySearch(nums, target, lo, mid - 1)
                   || binarySearch(nums, target, mid + 1, hi);
        }

        return nums[lo] == target;  // if lo == hi
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {1, 3, 4, 2, 2};
    std::cout << s.findDuplicate(input) << std::endl;   // 2

    input = vector<int> {3, 1, 3, 4, 2};
    std::cout << s.findDuplicate(input) << std::endl;   // 3

    input = vector<int> {1, 3, 4, 2, 1};
    std::cout << s.findDuplicate(input) << std::endl;   // 1

    return 0;
}
