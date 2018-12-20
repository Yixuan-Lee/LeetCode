#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return false;
        }

        size = static_cast<int> (nums.size());
        int pivot = findPivot(nums, target);
        if (isFoundTarget) {
            // if found the target while finding the pivot, then return
            // true immediately
            return true;
        }
        if (pivot == -1) {
            // there is something wrong
            return false;
        }
        // do binary search in the left and the right parts
        return binarySearch(nums, target, 0, pivot)
               || binarySearch(nums, target, pivot + 1, size) ? true : false;
    }

private:
    bool isFoundTarget = false;
    int size;

    int findPivot(const vector<int> &nums, const int target) {
        int i;
        for (i = 0; i < size - 1; i++) {
            if (nums[i] == target) {
                isFoundTarget = true;
                return 0;
            }
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }
        // compare the last element to the target
        if (nums[i] == target) {
            isFoundTarget = true;
        }
        return -1;
    }

    bool binarySearch(const vector<int> &nums, const int target, int left,
            int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > target) {
                // find in the left part
                right = mid - 1;
            } else if (nums[mid] < target) {
                // find in the right part
                left = mid + 1;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
//    vector<int> input {2, 5, 6, 0, 0, 1, 2};
    vector<int> input {};
    std::cout << s.search(input, 2) << std::endl;
    return 0;
}
