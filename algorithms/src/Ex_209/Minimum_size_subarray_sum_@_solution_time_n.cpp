#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        // declare and initialize the map
        //      hash.first: starting index
        //      hash.second: minimum length of subarray
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[i] = 0;
        }

        int sum = 0;
        int miniLen = 0;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            miniLen++;
            if (sum >= s) {
                hash[idx] = miniLen;
                sum = sum - nums[idx] - nums[i];
                i--;
                idx++;
                miniLen -= 2;
            }
        }

        int returnValue = hash[0];
        for (auto &it : hash) {
            if (it.second > 0 && it.second < returnValue) {
                returnValue = it.second;
            }
        }

        return returnValue;
    }
};


int main() {
    Solution s;
    vector<int> nums;
    int target;

    nums = vector<int> {2, 3, 1, 2, 4, 3};
    target = 7;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 2

    nums = vector<int> {1, 2, 3, 4, 5};
    target = 15;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 5

    nums = vector<int> {1, 1};
    target = 3;
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 0

    return 0;
}
