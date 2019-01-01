// references:
//      https://leetcode.com/problems/word-break/discuss/43790/Java-implementation-using-DP-in-two-ways
//      video: https://www.youtube.com/watch?v=8-AGBdUyZ5M


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool wordBreak(const string &s, vector<string> &wordDict) {
        if (s.empty() || wordDict.empty()) {
            return false;
        }
        auto size = s.size();

        // declare a vector which size is length of wordDict + 1
        vector<bool> dp(size + 1, false);
        // define the 0 index is always true
        dp[0] = true;

        // traverse the string s
        for (unsigned long i = 0; i <= size; i++) {
            // i is the starting index of current trial
            if (dp[i]) {
                // traverse the wordDict, if the substring is in the wordDict,
                // then update the dp, and try from i + 1
                for (const string &w : wordDict) {
                    auto len = w.size();
                    if (i + len <= size && s.substr(i, len) == w) {
                        dp[i + len] = true;
                    }
                }
            }
        }

        return dp[size];
    }
};


int main() {
    Solution s;
    vector<string> dict {
            "leet",
            "code"
    };
    std::cout << s.wordBreak("leetcode", dict) << std::endl;        // 1

    dict = vector<string> {
            "apple",
            "pen"
    };
    std::cout << s.wordBreak("applepenapple", dict) << std::endl;   // 1

    dict = vector<string> {
            "cats",
            "dog",
            "sand",
            "and",
            "cat"
    };
    std::cout << s.wordBreak("catsandog", dict) << std::endl;       // 0

    dict = vector<string> {
            "aaaa",
            "aaa"
    };
    std::cout << s.wordBreak("aaaaaaa", dict) << std::endl;         // 1

    dict = vector<string> {
            "a",
            "aa",
            "aaa",
            "aaaa",
            "aaaaa",
            "aaaaaa",
            "aaaaaaa",
            "aaaaaaaa",
            "aaaaaaaaa",
            "aaaaaaaaaa"
    };
    std::cout << s.wordBreak(
            "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab",
            dict) << std::endl;                                     // 0

    return 0;
}
