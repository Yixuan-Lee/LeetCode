#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (i < nums.size() / 2) {
                // if target is the first half element, then search the folloing elements first
                if (binarySearch(nums, nums[i], i + 1,
                        static_cast<int> (nums.size() - 1))
                    || binarySearch(nums, nums[i], 0, i - 1)) {
                    return nums[i];
                }
            } else {
                // if target is the second half element, then search the previous elements first
                if (binarySearch(nums, nums[i], 0, i - 1)
                    || binarySearch(nums, nums[i], i + 1,
                            static_cast<int> (nums.size() - 1))) {
                    return nums[i];
                }
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
            int temp_lo = lo;
            int temp_hi = hi;
            // always find in the left part
            while (temp_lo < temp_hi) {
                int mid = (temp_lo + temp_hi) / 2;
                if (nums[mid] == target) {
                    return true;
                } else {
                    temp_hi = mid - 1;
                }
            }
            // if haven't return in the while above, then always find in the right part
            temp_lo = lo;
            temp_hi = hi;
            while (temp_lo < temp_hi) {
                int mid = (temp_lo + temp_hi) / 2;
                if (nums[mid] == target) {
                    return true;
                } else {
                    temp_lo = mid + 1;
                }
            }
            // if haven't return in the while above, then repeat the process:
            //      1. then first find in the left part
            //      2. then find the the right part
            temp_lo = lo;
            temp_hi = hi;
            bool reverse = true;
            while (temp_lo < temp_hi) {
                int mid = (temp_lo + temp_hi) / 2;
                if (nums[mid] == target) {
                    return true;
                }
                if (reverse) {
                    temp_hi = mid - 1;
                    reverse = false;
                } else {
                    temp_lo = mid + 1;
                    reverse = true;
                }
            }
            // if haven't return in the while above, then repeat the process:
            //      1. then first find in the right part
            //      2. then find the the left part
            temp_lo = lo;
            temp_hi = hi;
            reverse = true;
            while (temp_lo < temp_hi) {
                int mid = (temp_lo + temp_hi) / 2;
                if (nums[mid] == target) {
                    return true;
                }
                if (reverse) {
                    temp_lo = mid + 1;
                    reverse = false;
                } else {
                    temp_hi = mid - 1;
                    reverse = true;
                }
            }
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

    input = vector<int> {8, 1, 1, 9, 5, 4, 2, 7, 3, 6};
    std::cout << s.findDuplicate(input) << std::endl;   // 1

    return 0;
}
