#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        if (size == 0) {
            return vector<int> {};
        }

        map<int, int> hash;
        for (const int &i : nums) {
            hash[i]++;
        }

        vector<int> ans;
        for (auto &it : hash) {
            if (it.second > size / 3) {
                ans.push_back(it.first);
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

    nums = vector<int> {3, 2, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [3]

    nums = vector<int> {1, 1, 1, 3, 3, 2, 2, 2};
    std::cout << s.majorityElement(nums) << std::endl;  // [1, 2]

    nums = vector<int> {3, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [3]

    nums = vector<int> {3, 3, 3};
    std::cout << s.majorityElement(nums) << std::endl;  // [3]

    nums = vector<int> {1, 2};
    std::cout << s.majorityElement(nums) << std::endl;  // [1, 2]

    nums = vector<int> {8, 8, 8, 8};
    std::cout << s.majorityElement(nums) << std::endl;  // [8]

    return 0;
}
