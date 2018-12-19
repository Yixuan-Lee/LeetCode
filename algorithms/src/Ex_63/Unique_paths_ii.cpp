#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        auto m = static_cast<int>(obstacleGrid.size());
        auto n = static_cast<int>(obstacleGrid[0].size());
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // initializes the 2d vector
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                dp[i][0] = 1;
            } else {
                // if there is an obstacle on (i,0), then the following
                // positions on the first row will not be reachable
                for (int k = i; k < m; k++) {
                    dp[k][0] = 0;
                }
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[0][j] == 0) {
                dp[0][j] = 1;
            } else {
                // if there is an obstacle on (0,j), then the following
                // positions on the first column will not be reachable
                for (int k = j; k < n; k++) {
                    dp[0][k] = 0;
                }
                break;
            }
        }

        // print the dp
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                std::cout << dp[i][j] << " ";
//            }
//            std::cout << std::endl;
//        }
//        std::cout << std::endl;

        // fill the table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    Solution s;
    vector<vector<int>> input {
            {0, 0, 0, 0},
            {0, 1, 0, 1},
            {0, 0, 0, 0},
            {1, 1, 0, 0}
    };
    std::cout << s.uniquePathsWithObstacles(input) << std::endl;
    return 0;
}

