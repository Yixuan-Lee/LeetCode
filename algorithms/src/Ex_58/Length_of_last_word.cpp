// references:
//      https://leetcode.com/problems/length-of-last-word/discuss/21892/7-lines-4ms-C%2B%2B-Solution


#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int lengthOfLastWord(string s) {
        auto length = static_cast<int>(s.length());
        if (length == 0) {
            return 0;
        }
        // find the index of last character
        int tail = length - 1;
        while (tail >= 0 && s[tail] == ' ') {
            tail--;
        }
        // calculate the length of last word
        int len = 0;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};


int main() {
    Solution s;
    string input = "     ";
    int length = s.lengthOfLastWord(input);
    std::cout << length << std::endl;
    return 0;
}
