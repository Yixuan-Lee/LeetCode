#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if (k < 0 || k > 9) {
            return ans;
        }
        if (k == 1 && n > 1 && n < 10) {
            ans.push_back(vector<int> {n});
            return ans;
        } else if (k == 1) {
            return ans;
        }

        vector<int> per;
        backtracking(ans, per, 1, k, n);
        return ans;
    }

private:
    void backtracking(vector<vector<int>> &ans, vector<int> &per,
            int startIdx, int k, int left) {
        if (per.size() > k) {
            return;
        }
        if (left == 0 && per.size() == k) {
            ans.push_back(per);
            return;
        }

        for (int i = startIdx; i <= 9; i++) {
            per.push_back(i);
            left -= i;
            backtracking(ans, per, i + 1, k, left);
            // backtrack
            left += i;
            per.pop_back();
        }
    }
};


// declare a template for overloading the << operator for vector<vector<<T>>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<vector<T>> &vec) {
    std::cout << "[" << std::endl;
    for (const vector<T> &v : vec) {
        std::cout << "\t[";
        for (const auto &i : v) {
            std::cout << i << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;

    std::cout << s.combinationSum3(3, 7) << std::endl;

    std::cout << s.combinationSum3(3, 9) << std::endl;

    std::cout << s.combinationSum3(3, 15) << std::endl;

    std::cout << s.combinationSum3(1, 7) << std::endl;

    std::cout << s.combinationSum3(1, 10) << std::endl;

    std::cout << s.combinationSum3(4, 24) << std::endl;

    return 0;
}
