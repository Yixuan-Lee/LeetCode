// references:
//      Cannot use std::sort to sort a set: https://stackoverflow.com/questions/13385348/sorting-sets-using-stdsort


#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;


class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        // at first, I wanted to declare unordered_map<int, set<int>> hash
        // but due to I cannot sort set, so i changed to vector<int>
        //
        // first: number value
        // second: indices where nums[i] equals to the number value
        unordered_map<int, vector<int>> hash;

        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash[nums[i]].push_back(i);
            } else {
                if (i - hash[nums[i]].back() <= k) {
                    return true;
                } else {
                    hash[nums[i]].push_back(i);
                }
            }
        }

        return false;
    }
};


int main() {
    Solution s;
    vector<int> input;
    int k;

    input = vector<int> {1, 2, 3, 1};
    k = 3;
    std::cout << s.containsNearbyDuplicate(input, k) << std::endl;      // 1

    input = vector<int> {1, 0, 1, 1};
    k = 1;
    std::cout << s.containsNearbyDuplicate(input, k) << std::endl;      // 1

    input = vector<int> {1, 2, 3, 1, 2, 3};
    k = 2;
    std::cout << s.containsNearbyDuplicate(input, k) << std::endl;      // 0

    return 0;
}
