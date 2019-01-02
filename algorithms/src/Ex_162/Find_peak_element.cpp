#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        auto size = static_cast<int> (nums.size());
        if (size == 1) {
            return 0;
        }
        if (nums[0] > nums[1]) {
            return 0;
        }
        if (nums[size - 1] > nums[size - 2]) {
            return size - 1;
        }

        int l = 1;
        int r = size - 2;
        return binarySearch(nums, l, r);
    }

private:
    int binarySearch(const vector<int> &nums, int l, int r) {
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else {
                int leftReturnVal = binarySearch(nums, l, mid - 1);
                int rightReturnVal = binarySearch(nums, mid + 1, r);
                return leftReturnVal != 0 ? leftReturnVal : rightReturnVal;
            }
        }
        return 0;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {1, 2, 3, 1};
    std::cout << s.findPeakElement(input) << std::endl; // 2

    input = vector<int> {1, 2, 1, 3, 5, 6, 4};
    std::cout << s.findPeakElement(input) << std::endl; // 1 or 5

    input = vector<int> {2, 1, 2, 3, 5, 6, 4};
    std::cout << s.findPeakElement(input) << std::endl; // 0 or 5

    input = vector<int> {1, 2, 3, 4, 5, 6, 7};
    std::cout << s.findPeakElement(input) << std::endl; // 6

    return 0;
}

