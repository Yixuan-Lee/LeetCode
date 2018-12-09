//
// Created by  liyixuan on 2018-11-22.
//
// reference:
//      https://leetcode.com/problems/search-insert-position/discuss/15080/My-8-line-Java-solution


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) {
            return 0;
        }

        if (target > nums[nums.size() - 1]) {
            return static_cast<int>(nums.size());
        } else if (target < nums[0]) {
            return 0;
        }

        int left = 0;
        int right = static_cast<int> (nums.size() - 1);
        int mid = 0;
        // try to find a position where nums[x] <= target and nums[x-1] >= target, then return x
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else if (target < nums[mid]) {
                right = mid - 1;
            }
        }
        // if there is no equivalent elements in the vector, then return the left value
        return left;
    }
};

int main() {
    Solution s;
    vector<int> vec {1};
    std::cout << s.searchInsert(vec, 1) << std::endl;
    return 0;
}