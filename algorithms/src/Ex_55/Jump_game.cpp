//
// Created by  liyixuan on 2018-12-06.
//
// references:
//      https://leetcode.com/articles/jump-game/   (great article)

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    bool canJump (vector<int> &nums) {
        if (nums.empty()) {
            return false;
        }

        return true;
    }
};


int main () {
    Solution s;
    double p = pow(57, 41);
    std::cout << p % 77 << std::endl;
//    vector<int> arr {2, 3, 1, 1, 4};
//    std::cout << s.canJump(arr) << std::endl;
    return 0;
}