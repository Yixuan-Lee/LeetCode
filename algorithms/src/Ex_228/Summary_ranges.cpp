#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ans;

        nums.push_back(INT_MAX);    // guard
        auto size = static_cast<int> (nums.size());
        bool range = false;
        string s;
        for (int i = 1; i < size; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                if (!range) {
                    s = std::to_string(nums[i - 1]) + "->";
                    range = true;
                }
            } else {
                if (range) {
                    s += std::to_string(nums[i - 1]);
                    ans.push_back(s);
                    s = "";
                    range = false;
                } else {
                    ans.push_back(std::to_string(nums[i - 1]));
                }
            }
        }

        return ans;
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    vector<int> nums;

    nums = vector<int> {0, 1, 2, 4, 5, 7};
    std::cout << s.summaryRanges(nums) << std::endl;    // [0->2, 4->5, 7]

    nums = vector<int> {0, 2, 3, 4, 6, 8, 9};
    std::cout << s.summaryRanges(nums) << std::endl;    // [0, 2->4, 6, 8->9]

    nums = vector<int> {0};
    std::cout << s.summaryRanges(nums) << std::endl;    // [0]

    nums = vector<int> {0, 1, 2, 3, 4, 5};
    std::cout << s.summaryRanges(nums) << std::endl;    // [0->5]

    return 0;
}
