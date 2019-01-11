// references:
//      https://en.cppreference.com/w/cpp/algorithm/min_element


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        vector<int> mini;
        for (int i = 0; i < nums.size(); i++) {
            int minimumLen = 0;
            int sum = 0;

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                minimumLen++;
                if (sum >= s) {
                    mini.push_back(minimumLen);
                    break;
                }
            }
        }

        if (mini.empty()) {
            return 0;
        } else {
            return mini[(
                    std::distance(std::begin(mini),
                            std::min_element(std::begin(mini),
                                    std::end(mini))))];
        }
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
    std::cout << s.minSubArrayLen(target, nums) << std::endl;   // 3

    return 0;
}
