// reference:
//      https://leetcode.com/articles/container-with-most-water/


#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() < 2) {
            return 0;
        }
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int length = right - left;
            int width = (int) fmin(height[left], height[right]);
            int area = length * width;
            if (area > maxArea) {
                maxArea = area;
            }
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution s;
    vector<int> height {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << s.maxArea(height) << std::endl;
    return 0;
}