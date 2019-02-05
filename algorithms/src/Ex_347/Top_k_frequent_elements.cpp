#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        auto size = static_cast<int> (nums.size());
        // first: occurrence times
        // second: numbers corresponding to the occurrence times
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i <= size; i++) {
            hash[i] = vector<int> {};
        }

        // first: number
        // second: occurrence times of the number
        unordered_map<int, int> frequencies;
        for (int i = 0; i < size; i++) {
            if (std::find(hash[frequencies[nums[i]]].begin(),
                    hash[frequencies[nums[i]]].end(), nums[i])
                != hash[i].end()) {
                // remove nums[i] from hash[i]
                hash[frequencies[nums[i]]].erase(
                        std::remove(hash[frequencies[nums[i]]].begin(),
                                hash[frequencies[nums[i]]].end(), nums[i]),
                        hash[frequencies[nums[i]]].end());
            }

            frequencies[nums[i]]++;
            // insert nums[i] in hash[frequencies[nums[i]]]
            hash[frequencies[nums[i]]].push_back(nums[i]);
        }

        if (k > size) {
            return vector<int> {};
        }

        vector<int> ans;
        for (int i = size; i >= 0 && ans.size() < k; i--) {
            if (hash[i].empty()) {
                continue;
            }
            for (int j = 0; j < hash[i].size() && ans.size() < k; j++) {
                ans.push_back(hash[i][j]);
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

    nums = vector<int> {1, 1, 1, 2, 2, 3};
    std::cout << s.topKFrequent(nums, 2) << std::endl;  // [1, 2]

    nums = vector<int> {1};
    std::cout << s.topKFrequent(nums, 1) << std::endl;  // [1]

    nums = vector<int> {5, 3, 1, 1, 1, 3, 73, 1};
    std::cout << s.topKFrequent(nums, 2) << std::endl;  // [1, 3]

    return 0;
}
