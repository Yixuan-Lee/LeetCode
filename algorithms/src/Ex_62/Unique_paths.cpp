// references:
//      https://leetcode.com/problems/unique-paths/discuss/204632/topic


#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        // initializes the 2d vector
        for (int i = 0; i < m; i++) {
            // only 1 path from (0,0) to (i,0)
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            // only 1 path from (0,0) to (0,j)
            dp[0][j] = 1;
        }

        // fill the table
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // possible paths from (0,0) to (i,j) equal (1) + (2)
                //   (1) possible paths from (0,0) to (i-1,j)
                //   (2) possible paths from (0,0) to (i,j-1)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    Solution s;
    std::cout << s.uniquePaths(23, 12) << std::endl;
    return 0;
}