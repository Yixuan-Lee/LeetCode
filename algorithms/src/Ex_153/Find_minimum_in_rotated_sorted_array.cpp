#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        return nums[binarySearch(nums, 0,
                static_cast<int> (nums.size() - 1), 0)];
    }

private:
    /**
     * find a pair <p, q> in which q is smaller than p, that is, the position
     * of rotation
     *
     * @param nums numbers
     * @param lo   left position
     * @param hi   right position
     * @param pos  rotation position
     *
     * @return     rotation position
     */
    int binarySearch(const vector<int> &nums, int lo, int hi, int pos) {
        if (lo >= hi) {
            return 0;
        }

        int mid = (lo + hi) / 2;
        if (nums[mid] > nums[mid + 1]) {
            pos = mid + 1;
            return pos;
        } else {
            // because if there is no pair found, then return 0, so we can
            // plus the two sub-results to get the inflection point
            pos = binarySearch(nums, lo, mid, pos)
                  + binarySearch(nums, mid + 1, hi, pos);
        }

        return pos;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {3, 4, 5, 1, 2};
    std::cout << s.findMin(input) << std::endl;     // 1

    input = vector<int> {4, 5, 6, 7, 0, 1, 2};
    std::cout << s.findMin(input) << std::endl;     // 0

    input = vector<int> {0, 1, 2, 3, 4, 5, 6};
    std::cout << s.findMin(input) << std::endl;     // 0

    input = vector<int> {1};
    std::cout << s.findMin(input) << std::endl;     // 1

    input = vector<int> {};
    std::cout << s.findMin(input) << std::endl;     // 0

    input = vector<int> {3, 1, 2};
    std::cout << s.findMin(input) << std::endl;     // 1

    input = vector<int> {3, 4, 2};
    std::cout << s.findMin(input) << std::endl;     // 2

    input = vector<int> {2, 3, 4, 5, 1};
    std::cout << s.findMin(input) << std::endl;     // 1

    return 0;
}
