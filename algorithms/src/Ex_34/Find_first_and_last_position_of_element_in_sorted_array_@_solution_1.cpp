#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> res {-1, -1};
        if (nums.empty()) {
            return res;
        }

        int position = this->binarySearch(nums, target);
        if (position == -1) {
            return res;
        }

        int size = static_cast<int>(nums.size());
        int i, j;
        for (i = position; i >= 0 && nums[i] == target; i--);
        for (j = position; j < size && nums[j] == target; j++);

        res[0] = i + 1;
        res[1] = j - 1;
        return res;
    }

private:
    int binarySearch(vector<int> &nums, int target) {
        int l = 0;
        int r = static_cast<int>(nums.size() - 1);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<int> vec {1};
    int target = 1;

    vector<int> res = s.searchRange(vec, target);
    std::cout << "[";
    for (int i : res) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return 0;
}
