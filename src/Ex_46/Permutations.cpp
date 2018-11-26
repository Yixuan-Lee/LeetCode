//
// Created by  liyixuan on 2018-11-26.
//
// reference:
//      https://leetcode.com/problems/permutations/discuss/18239/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partioning)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return res;
        }
        vector<int> per;
        backtracking(nums, per);
        return res;
    }

private:
    void backtracking(vector<int>& nums, vector<int>& per) {
        if (per.size() == nums.size()) {
            res.push_back(per);
            return;
        }
        int length = static_cast<int>(nums.size());
        for (int i = 0; i < length; i++) {
            // if nums[i] exists in per, then try next element
            if (std::find(per.begin(), per.end(), nums[i]) != per.end()) {
                continue;
            }
            per.push_back(nums[i]);
            backtracking(nums, per);
            per.pop_back();
        }
    }

    vector<vector<int>> res;
};


int main() {
    Solution s;
    vector<int> vec {1, 2, 3, 4};
    vector<vector<int>> res = s.permute(vec);
    for (const vector<int>& v : res) {
        std::cout << '[';
        for (const int&i : v) {
            std::cout << i << ", ";
        }
        std::cout << ']' << std::endl;
    }
    return 0;
}