//
// Created by  liyixuan on 2018-12-02.
//
// references:
//      https://en.cppreference.com/w/cpp/language/lambda

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> searchRange (vector<int> &nums, int target) {
        vector<int> res {-1, -1};
        if (nums.empty()) {
            return res;
        }

        int size = static_cast<int>(nums.size());
        int position = this->binarySearch(nums, target, 0, size);
        if (position == -1) {
            return res;
        }

        if (size == 1) {
            return vector<int> {0, 0};
        }

        if (nums[position - 1] != target) {
            // if left element and right element of the position do not equal
            // to the target, then return the position
            if (nums[position + 1] != target) {
                return vector<int> {position, position};
            } else {
                // if left element does not equal to the target, but
                // the right element equals to the target, then:
                //
                // if find another target in the right sub-array, then
                // keep finding in the right sub-sub-array of the
                // right sub-array
                //
                // if not find another target in the right sub-array, then
                // keep finding in the left sub-sub-array of the
                // right sub-array
                int right = binarySearch(nums, target, position + 1, size);
                while (right == -1) {
                    right = binarySearch(nums, target, position + 1, size);

                }
            }
        } else {
            // if left element equals to the target, but
            // right element does not equal to the target, then
            //
            // do binary search in the left sub-array recursively
            if (nums[position + 1] != target) {

            } else {
                // if left element and right element both equal to the target,
                // then do binary search recursively in both left and right
                // sub-array
            }
        }

        int left = position;
        int right = position;


        return res;
    }

private:
    int binarySearch (vector<int> &nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};


int main () {
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
