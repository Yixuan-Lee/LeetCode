// references:
//      https://leetcode.com/articles/majority-element/


#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {3, 2, 3};
    std::cout << s.majorityElement(input) << std::endl;     // 3

    input = vector<int> {2, 2, 1, 1, 1, 2, 2};
    std::cout << s.majorityElement(input) << std::endl;     // 2

    input = vector<int> {2, 2, 2, 2, 4, 5, 6, 2};
    std::cout << s.majorityElement(input) << std::endl;     // 2

    input = vector<int> {4, 8, 6, 7, 8, 8, 8, 8};
    std::cout << s.majorityElement(input) << std::endl;     // 8

    return 0;
}
