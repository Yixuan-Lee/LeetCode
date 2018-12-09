//
// Created by  liyixuan on 2018-11-20.
//

#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty() || needle.length() == 0) {
            return 0;
        }
        if (haystack.empty() || haystack.length() == 0) {
            return -1;
        }

        int length = static_cast<int>(haystack.length());
        int j = 0;
        for (int i = 0; i < length; i++) {
            if (haystack[i] == needle[j]) {
                int k = i;
                while (k < length && j < needle.length() && haystack[k] == needle[j]) {
                    k++;
                    j++;
                }
                if (j == needle.length()) {
                    return i;
                } else {
                    j = 0;
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    std::cout << s.strStr("aaa", "aaaa") << std::endl;
    return 0;
}

