//
// Created by  liyixuan on 2018-11-25.
//

#include <iostream>
#include <vector>


using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) {
            return res;
        }
        if (target <= 0) {
            return res;
        }
        vector<int> combinations;
        const int size = static_cast<const int>(candidates.size());
        bool* flags = new bool[size];
        memset(flags, true, candidates.size() * sizeof(bool));
        findCombinations(candidates, target, combinations, flags, 0);
        delete(flags);

        // remove duplicates
        for (vector<int>& v : res) {
            std::sort(v.begin(), v.end());
        }
        std::sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());

        return res;
    }

private:
    void findCombinations(vector<int>& candidates, const int target, vector<int>& combination, bool* flags, int startPosition) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = startPosition; i < candidates.size(); i++) {
            if (*(flags + i)) {
                combination.push_back(candidates[i]);
                *(flags + i) = false;
            }
            findCombinations(candidates, target - candidates[i], combination, flags, i + 1);
            *(flags + i) = true;
            combination.pop_back();
        }
    }

    vector<vector<int>> res;
};

int main() {
    Solution s;
    vector<int> candidates {2, 5, 2, 1, 2};
    int target = 5;
    vector<vector<int>> res = s.combinationSum2(candidates, target);
    for (const vector<int>& v : res) {
        std::cout << '[';
        for (const int&i : v) {
            std::cout << i << ", ";
        }
        std::cout << ']' << std::endl;
    }
    return 0;
}