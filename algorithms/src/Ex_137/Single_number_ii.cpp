// references:
//      https://leetcode.com/problems/single-number-ii/discuss/43296/An-General-Way-to-Handle-All-this-sort-of-questions.


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int a = 0;
        int b = 0;
        for (const auto &i : nums) {
            int temp = (~a & b & i) | (a & ~b & ~i);
            b = (~a & ~b & i) | (~a & b & ~i);
            a = temp;
        }
        return a | b;
    }
};


int main() {
    Solution s;
    vector<int> input {2, 2, 3, 2};
//    vector<int> input {0, 1, 0, 1, 0, 1, 99};
    std::cout << s.singleNumber(input) << std::endl;
    return 0;
}

