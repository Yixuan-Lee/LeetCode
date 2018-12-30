// reference:
//      https://stackoverflow.com/questions/42850924/leetcode-twosum-solution
//      https://stackoverflow.com/questions/15451287/what-does-iterator-second-mean


#include <iostream>
#include <map>
#include <vector>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = m.find(complement);
            if (it != m.end()) {
                return vector<int> {it->second, i};
            }
            m[nums[i]] = i;
        }
    }
};

int main() {
    vector<int> nums {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    for (int i : result) {
        std::cout << i << std::endl;
    }
    return 0;
}
