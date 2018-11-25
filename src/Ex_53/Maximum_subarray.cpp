//
// Created by  liyixuan on 2018-11-25.
//
// reference:
//      https://leetcode.com/problems/maximum-subarray/discuss/197808/bottom-up-version-of-DP-with-java.-beats-99.95


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int length = static_cast<int>(nums.size());
        for (int i = 1; i < length; i++) {
            nums[i] = std::max(nums[i] + nums[i-1], nums[i]);
            if (nums[i] > max) {
                max = nums[i];
            }
        }
        return max;
    }
};


int main() {
    Solution s;
    vector<int> v {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << s.maxSubArray(v) << std::endl;
    return 0;
}