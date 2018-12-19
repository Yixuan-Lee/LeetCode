// references:
//      https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        // gets number of rows
        auto m = static_cast<int> (grid.size());
        // gets number of columns
        auto n = static_cast<int> (grid[0].size());

        // initializes dp vector
        vector<vector<int>> dp(m, vector<int>(n, 0));
//        std::cout << m << std::endl;
//        std::cout << n << std::endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = grid[i][j];
            }
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] += dp[i - 1][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0][j] += dp[0][j - 1];
        }

//        // print the dp
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                std::cout << dp[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
//        std::cout << std::endl;

        // calculate the minimum path sum for every position
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] += std::min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    Solution s;
    vector<vector<int>> input {
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };
    std::cout << s.minPathSum(input) << std::endl;
    return 0;
}
