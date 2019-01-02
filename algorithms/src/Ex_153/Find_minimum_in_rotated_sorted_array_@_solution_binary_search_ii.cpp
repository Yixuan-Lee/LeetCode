// references:
//      https://leetcode.com/submissions/detail/198535712/ (sample 4ms submission)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        return findMinRange(nums, 0, static_cast<int> (nums.size()));
    }

private:
    int findMinRange(const vector<int> &nums, int lo, int hi) {
        if (lo + 1 >= hi) {
            return nums[lo];
        }
        if (nums[lo] > nums[hi - 1]) {
            // there is an inflection point in the range (lo, hi)
            int mid = (lo + hi) / 2;
            int minL = findMinRange(nums, lo, mid);
            int minR = findMinRange(nums, mid, hi);

            return minL < minR ? minL : minR;
        }
        // we are at one side of the inflection point
        return nums[lo];
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

    input = vector<int> {2, 1};
    std::cout << s.findMin(input) << std::endl;     // 1

    return 0;
}
