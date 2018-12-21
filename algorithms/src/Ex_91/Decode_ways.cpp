// references:
//      https://leetcode.com/problems/decode-ways/discuss/30357/DP-Solution-(Java)-for-reference


#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    int numDecodings(string s) {
        int ways = 0;
        auto length = s.length();
        if (length == 0) {
            return ways;
        }

        vector<int> dp(length + 1, 0);
        dp[length] = 1;
        dp[length - 1] = s[length - 1] != '0' ? 1 : 0;

        for (int i = static_cast<int> (length - 2); i >= 0; i--) {
            if (s[i] == '0') {
                continue;
            } else {
                dp[i] = std::stoi(s.substr(i, 2)) <= 26
                        ? dp[i + 1] + dp[i + 2]
                        : dp[i + 1];
            }
        }
        return dp[0];
    }
};


int main() {
    Solution s;
    std::cout << s.numDecodings("10101") << std::endl;
    return 0;
}
