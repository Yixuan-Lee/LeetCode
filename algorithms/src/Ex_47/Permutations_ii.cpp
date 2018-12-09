//
// Created by  liyixuan on 2018-11-27.
//
// references:
//      https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines
//      https://stackoverflow.com/questions/1041620/whats-the-most-efficient-way-to-erase-duplicates-and-sort-a-vector


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) {
            return res;
        }
        std::sort(nums.begin(), nums.end());
        nums_size = nums.size();
        backtracking(nums, 0);
        // remove duplicates
        std::sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }

private:
    vector<vector<int>> res;
    unsigned long nums_size = 0;

    void backtracking(vector<int>& nums, int start) {
        if (start == nums_size - 1) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums_size; i++) {
            if (i == start || nums[i] != nums[start]) {
                std::swap(nums[i], nums[start]);
                backtracking(nums, start + 1);
                // attention: must swap back after backtracking, need to keep the original state
                std::swap(nums[start], nums[i]);
            }
        }
    }
};


int main() {
    Solution s;
    vector<int> vec {1, 3, 2};
    vector<vector<int>> res = s.permuteUnique(vec);
    for (const vector<int>& v : res) {
        std::cout << '[';
        for (const int&i : v) {
            std::cout << i << ", ";
        }
        std::cout << ']' << std::endl;
    }
    return 0;
}