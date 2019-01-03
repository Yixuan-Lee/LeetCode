// references:
//      https://leetcode.com/articles/majority-element/


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        return divideAndConquer(nums, 0, static_cast<int> (nums.size() - 1));
    }

private:
    int divideAndConquer(const vector<int> &nums, int lo, int hi) {
        if (lo == hi) {
            // only one element in the sub-array, so that has to be
            // the majority element
            return nums[lo];
        }

        // get the majority elements in the left and right halves
        int mid = (hi - lo) / 2 + lo;
        int leftMajorityElement = divideAndConquer(nums, lo, mid);
        int rightMajorityElement = divideAndConquer(nums, mid + 1, hi);

        if (leftMajorityElement == rightMajorityElement) {
            return leftMajorityElement;
        } else {
            // count the two elements in the bigger sub-array,
            // and return the right majority element
            int leftMajorityElementCount = countInRange(nums,
                    leftMajorityElement, lo, hi);
            int rightMajorityElementCount = countInRange(nums,
                    rightMajorityElement, lo, hi);

            return leftMajorityElementCount > rightMajorityElementCount
                   ? leftMajorityElement : rightMajorityElement;
        }
    }

    int countInRange(const vector<int> &nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == target) {
                count++;
            }
        }
        return count;
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {3, 2, 3};
    std::cout << s.majorityElement(input) << std::endl;

    input = vector<int> {2, 2, 1, 1, 1, 2, 2};
    std::cout << s.majorityElement(input) << std::endl;

    return 0;
}
