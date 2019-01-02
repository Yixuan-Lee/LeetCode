// references:
//      https://stackoverflow.com/questions/1798112/removing-leading-and-trailing-spaces-from-a-string


#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    void reverseWords(string &s) {
        if (s.empty()) {
            return;
        }

        // iterate from the end
        auto idx = static_cast<int> (s.size() - 1);
        bool wordStart = false;
        string newStr;
        while (idx >= 0) {
            if (!isspace(s[idx])) {
                wordStart = true;
            } else if (s[idx] == ' ') {
                if (wordStart) {
                    int curIdx = idx + 1;
                    while (curIdx < s.size() && !isspace(s[curIdx])) {
                        newStr += s[curIdx++];
                    }
                    newStr += " ";
                    wordStart = false;
                }
            } else {
                wordStart = false;
            }
            idx--;
        }
        if (wordStart && idx == -1) {
            int curIdx = idx + 1;
            while (curIdx < s.size() && !isspace(s[curIdx])) {
                newStr += s[curIdx++];
            }
        }
        newStr = trim(newStr);
        s = newStr;
    }

private:
    const string whitespace = " ";

    string trim(const string &str) {

        const auto strBegin = str.find_first_not_of(whitespace);
        if (strBegin == std::string::npos) {
            return "";
        }

        const auto strEnd = str.find_last_not_of(whitespace);
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }
};


int main() {
    Solution s;
    string str;

    str = "the sky is blue";
    s.reverseWords(str);
    std::cout << str << std::endl;

    str = "   the   sky   is   blue  ";
    s.reverseWords(str);
    std::cout << str << std::endl;

    str = "   a1  2  ";
    s.reverseWords(str);
    std::cout << str << std::endl;

    str = "1  2b  ";
    s.reverseWords(str);
    std::cout << str << std::endl;

    str = "hi!";
    s.reverseWords(str);
    std::cout << str << std::endl;

    str = "  hi, world!   ";
    s.reverseWords(str);
    std::cout << str << std::endl;

    return 0;
}
