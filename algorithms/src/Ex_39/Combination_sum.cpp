//
// Created by  liyixuan on 2018-11-24.
//
// reference:
//      https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (!target) {
            return res;
        }
        vector<int> combination;    // store the intermediate combination result
        findCombinations(candidates, target, res, combination, 0);
        return res;
    }

private:
    void findCombinations(vector<int>& candidates, int target, vector<vector<int>>& res,
            vector<int>& combination, int beginPosition) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = beginPosition; i < candidates.size(); i++) {
            combination.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates {8, 7, 4, 3};
    int target = 11;
    vector<vector<int>> res = s.combinationSum(candidates, target);
    for (const vector<int>& v : res) {
        std::cout << '[';
        for (const int&i : v) {
            std::cout << i << ", ";
        }
        std::cout << ']' << std::endl;
    }
    return 0;
}