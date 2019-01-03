#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // first: number
        // second: index
        unordered_map<int, int> hash;
        // insert all numbers into a map
        for (int i = 0; i < numbers.size(); i++) {
            hash[numbers[i]] = i;
        }

        for (int idx1 = 0; idx1 < numbers.size() - 1; idx1++) {
            int remainder = target - numbers[idx1];
            if (hash.find(remainder) != hash.end()) {
                return vector<int> {idx1 + 1, hash[remainder] + 1};
            }
        }

        return vector<int> {-1, -1};
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

    nums = vector<int> {2, 7, 11, 15};
    std::cout << s.twoSum(nums, 9) << std::endl;    // [1,2]

    nums = vector<int> {2, 7, 11, 15};
    std::cout << s.twoSum(nums, 22) << std::endl;   // [2,4]

    return 0;
}
