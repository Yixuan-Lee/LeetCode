//
// Created by  liyixuan on 2018-12-11.
//
// references:
//      https://leetcode.com/problems/sqrtx/discuss/25066/Solve-this-problem-with-Binary-Search


#include <iostream>
#include <cmath>

class Solution {
public:
    int mySqrt (int x) {
        int left = 1;
        int right = x;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (mid <= x / mid) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

};


int main () {
    Solution s;
    int input = 0;
    std::cout << s.mySqrt(input) << std::endl;
    return 0;
}