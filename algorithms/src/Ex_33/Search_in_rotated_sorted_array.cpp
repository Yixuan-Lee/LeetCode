#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        // first, find the rotation position (a[i] > a[i+1]) and set idx_rotation
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);
        findRotationPosition(nums, left, right);

        // find on the left sub-array
        int res = -1;
        left = 0;
        right = idx_rotation;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) {
                res = mid;
                break;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            }
        }

        // if have not found yet, then find on the right sub-array
        if (res == -1) {
            left = idx_rotation + 1;
            right = static_cast<int>(nums.size() - 1);
            while (left <= right) {
                int mid = (left + right) / 2;
                if (target == nums[mid]) {
                    res = mid;
                    break;
                } else if (target > nums[mid]) {
                    left = mid + 1;
                } else if (target < nums[mid]) {
                    right = mid - 1;
                }
            }
        }
        return res;
    }

private:
    /**
     * stores the rotation position (index)
     *
     * for example:
     *      if array is {4, 5, 6, 7, 0, 1, 2}, then idx_rotation should be 3
     */
    int idx_rotation = -1;

    /**
     * find the rotation position
     *
     * @param nums array
     * @param left left position
     * @param right right position
     */
    void findRotationPosition(const vector<int> &nums, int left, int right) {
        if (left > right) {
            return;
        }

        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1]) {
            idx_rotation = mid;
        } else {
            // if haven't found the rotation position, keep finding on the left sub-array
            findRotationPosition(nums, left, mid - 1);
        }
        if (idx_rotation == -1) {
            // if haven't found the rotation position, keep finding on the right sub-array
            findRotationPosition(nums, mid + 1, right);
        }
    }

};

int main() {
    Solution s;
    vector<int> nums {4, 5, 6, 7, 0, 1, 2};
    std::cout << s.search(nums, 7) << std::endl;
    return 0;
}
