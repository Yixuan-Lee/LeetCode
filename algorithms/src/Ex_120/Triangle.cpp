#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty()) {
            return 0;
        }
        vector<vector<int>> dp;
        // initializes dp, just copy triangle
        for (const auto &v : triangle) {
            dp.push_back(v);
        }

        dp[0][0] = triangle[0][0];
        auto rows = static_cast<int> (triangle.size());
        for (int i = 1; i < rows; i++) {
            auto cols = static_cast<int> (triangle[i].size());
            for (int j = 0; j < cols; j++) {
                if (j - 1 < 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                    continue;
                }
                if (j == dp[i - 1].size()) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                    continue;
                }
                dp[i][j] = std::min(dp[i - 1][j - 1], dp[i - 1][j])
                           + triangle[i][j];
            }
        }
        int min = INT32_MAX;
        auto cols = static_cast<int> (triangle[rows - 1].size());
        for (int i = 0; i < cols; i++) {
            if (dp[rows - 1][i] < min) {
                min = dp[rows - 1][i];
            }
        }
        return min;
    }
};


int main() {
    Solution s;
    vector<vector<int>> input {
            {2},
            {3, 4},
            {6, 5, 7},
            {4, 1, 8, 3}
    };

//    vector<vector<int>> input {
//            {2},
//            {3, 4},
//    };

//    vector<vector<int>> input {
//            {2},
//    };
    std::cout << s.minimumTotal(input) << std::endl;
    return 0;
}
