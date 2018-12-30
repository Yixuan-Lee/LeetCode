// references:
//      https://leetcode.com/problems/single-number-ii/discuss/43297/Java-O(n)-easy-to-understand-solution-easily-extended-to-any-times-of-occurance


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (auto num : nums) {
                if (((num >> i) & 1) == 1) {
                    sum++;
                    sum %= 3;
                }
            }
            if (sum != 0) {
                ans |= sum << i;
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> input {2, 2, 3, 2};
//    vector<int> input {0, 1, 0, 1, 0, 1, 99};
    std::cout << s.singleNumber(input) << std::endl;
    return 0;
}


