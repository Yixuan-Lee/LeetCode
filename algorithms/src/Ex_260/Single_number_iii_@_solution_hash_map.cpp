#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::vector;

class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        map<int, int> hash;
        for (auto &i : nums) {
            hash[i]++;
        }

        vector<int> ans;
        for (auto &it : hash) {
            if (it.second == 1) {
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

    nums = vector<int> {1, 2, 1, 3, 2, 5};
    std::cout << s.singleNumber(nums) << std::endl;     // [3, 5]


    return 0;
}
