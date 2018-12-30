#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        string longestStr = "";
        int strs_size = strs.size();
        int i, j;
        // choose the longest string in strs
        for (i = 0; i < strs_size; i++) {
            if (strs[i].length() > longestStr.length()) {
                longestStr = strs[i];
            }
        }
        // get the longest common prefix
        int longestSrtr_length = longestStr.length();
        string longestPrefix = "";
        for (j = 0; j < longestSrtr_length; j++) {
            char c = longestStr[j];
            for (i = 0; i < strs_size; i++) {
                if (strs[i][j] != c) {
                    return longestPrefix;
                }
            }
            if (i == strs_size) {
                longestPrefix += c;
            }
        }
        return longestPrefix;
    }
};

int main() {
    Solution s;
    vector<string> s1 {"abab", "aba", ""};
    std::cout << s.longestCommonPrefix(s1) << std::endl;
    return 0;
}
