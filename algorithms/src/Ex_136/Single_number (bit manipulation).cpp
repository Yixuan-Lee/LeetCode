// references:
//      https://leetcode.com/submissions/detail/197825022/ (sample 8ms submission)

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
//        int size = static_cast<int> (nums.size());
        for (int i = 1; i < nums.size(); nums[0] ^= nums[i], i++);
        return nums[0];
    }
};


int main() {
    Solution s;
    vector<int> input {2, 2, 1};
//    vector<int> input {4, 1, 2, 1, 2};
    std::cout << s.singleNumber(input) << std::endl;
    return 0;
}

