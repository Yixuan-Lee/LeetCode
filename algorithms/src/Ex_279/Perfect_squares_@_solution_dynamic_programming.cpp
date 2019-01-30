// references:
//      https://leetcode.com/problems/perfect-squares/discuss/71495/An-easy-understanding-DP-solution-in-Java


#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(static_cast<unsigned long> (n + 1), 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        if (n <= 3) {
            return dp[n];
        }
        for (int i = 4; i <= n; i++) {
            int min = INT_MAX;
            for (int j = 1; i - j * j >= 0; j++) {
                // update the minimum steps to get i
                min = std::min(min, dp[i - j * j] + 1);
            }
            dp[i] = min;
        }

        return dp[n];
    }
};


int main() {
    Solution s;
    int n;

    n = 12;
    std::cout << s.numSquares(n) << std::endl;      // 3

    n = 13;
    std::cout << s.numSquares(n) << std::endl;      // 2

    n = 26;
    std::cout << s.numSquares(n) << std::endl;      // 2

    n = 51;
    std::cout << s.numSquares(n) << std::endl;      // 3

    return 0;
}
