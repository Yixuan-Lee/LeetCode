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

        map<int, vector<int>> hash;
        for (int i = 1; i <= size; i++) {
            hash[i] = vector<int> {};
        }

        for (int i = 0; i < size; i++) {
            if (i == (2 * size) / 3 + 2 && hash[1].size() == i) {
                return vector<int> {};
            }

            int j;
            for (j = 1; j <= size / 2; j++) {
                if (std::find(hash[j].begin(), hash[j].end(), nums[i])
                    != hash[j].end()) {
                    // remove nums[i] in hash[i] to hash[i+1]
                    hash[j].erase(std::remove(hash[j].begin(), hash[j].end(),
                            nums[i]), hash[j].end());
                    hash[j + 1].push_back(nums[i]);
                    break;
                }
            }
            if (j == size / 2 + 1) {
                hash[1].push_back(nums[i]);
            }
        }

        vector<int> ans;
        for (int i = size / 3 + 1; i <= size / 2 + 1; i++) {
            for (const int &j : hash[i]) {
                ans.push_back(j);
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
