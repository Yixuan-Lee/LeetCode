#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, bool> hash;
        for (auto &i : nums) {
            if (hash[i]) {
                return true;
            }
            hash[i] = true;
        }

        return false;
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
