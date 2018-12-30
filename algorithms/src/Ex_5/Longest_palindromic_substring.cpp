// reference:
//      https://leetcode.com/articles/longest-palindromic-substring/
//      https://www.programcreek.com/2013/12/leetcode-solution-of-longest-palindromic-substring-java/
//      http://www.cplusplus.com/reference/string/string/substr/


#include <iostream>
#include <string>
#include <cmath>

using std::string;

class Solution {
public:
    // Solution 1:
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        if (s.length() == 1) {
            return s;
        }

        int length = s.length();
        int lengthOfLP = 0;
        bool dp[length][length];
        string longest;
        for (int i = 0; i < length; i++) {
            // i is the starting position
            for (int j = 0; j < length - i; j++) {
                int k = j + i;      // k is the ending position
                if (s[j] == s[k] && (k - j <= 2 || dp[j + 1][k - 1])) {
                    dp[j][k] = true;

                    if (k - j + 1 > lengthOfLP) {
                        lengthOfLP = k - j + 1;
                        longest = s.substr(j, lengthOfLP);
                    }
                }
            }
        }
        // print the dp matrix
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < length; j++) {
                std::cout << dp[i][j] << " ";
            }
            std::cout << std::endl;
        }
        return longest;
    }


    // Solution 2:
    /*
    string longestPalindrome(string s) {
        if (s.length() == 0) {
            return "";
        }
        int start = 0, end = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            int len1 = expandAroundCenter(s, i, i);     // the center of the string is the letter s[i]
            int len2 = expandAroundCenter(s, i, i+1);   // the center of the string is between letter s[i] and s[i+1]
            int len = (int) fmax(len1, len2);
            if (len > end - start) {
                // why there needs to subtract 1??
                // answer:
                // because if I type in "bb", then i = 0, len1 = 1, len2 = 2, len = 2
                // and start will equal 0 - (2 - 1) / 2, which is 0, if don't subtract 1 here
                // start will equal to -1, which will cause out-of-bound exception
                start = i - (len - 1) / 2;  // set the starting position of new longest palindrome
                end = i + len / 2;          // set the ending position of new longest palindrome
            }
        }
        // string::substr(position, length)
        return s.substr(start, end + 1 - start);    // return s[start...end]
    }

    int expandAroundCenter(string s, int left, int right) {
        int l = left, r = right;
        int length = s.length();
        while (l >= 0 && r < length && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
        // why there needs subtract 1 ?
        // answer:
        // because what will be returned here is the length of palindrome
        // if l = 0, r = 0, then after one loop, l = -1, r = 1, we need to return 1, so 1 = r - l - 1
        // if l = 0, r = 1, then after one loop, l = -1, r = 2, we need to return 2, so 2 = r - l - 1
    }
    */
};

int main() {
    Solution s;
    string str;
    std::cin >> str;
    std::cout << s.longestPalindrome(str) << std::endl;
    return 0;
}
