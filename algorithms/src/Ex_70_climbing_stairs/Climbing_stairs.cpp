#include <iostream>
#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1, 0);
        // initializes the dp
        // 0 way to 0
        // 1 way to 1
        // 2 ways to 2
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        if (n <= 2) {
            return dp[n];
        }
        for (int i = 3; i <= n; i++) {
            // possible ways to i equal (1) + (2)
            //   (1) possible ways to i-1
            //   (2) possible ways to i-2
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};


int main() {
    Solution s;
    std::cout << s.climbStairs(6) << std::endl;
    return 0;
}

