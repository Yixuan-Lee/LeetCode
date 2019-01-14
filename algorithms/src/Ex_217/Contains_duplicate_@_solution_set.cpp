// references:
//      https://leetcode.com/submissions/detail/201219608/  (sample 36ms submission)


#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};


int main() {
    Solution s;
    vector<int> input;

    input = vector<int> {1, 2, 3, 1};
    std::cout << s.containsDuplicate(input) << std::endl;   // 1

    input = vector<int> {1, 2, 3, 4};
    std::cout << s.containsDuplicate(input) << std::endl;   // 0

    input = vector<int> {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout << s.containsDuplicate(input) << std::endl;   // 1

    return 0;
}
