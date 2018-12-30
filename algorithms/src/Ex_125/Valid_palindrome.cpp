#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }

        auto length = static_cast<int> (s.size());
        int start = 0;
        int end = length - 1;
        bool isPalindrome = true;

        while (start < end) {
            char startChar = ' ';
            while (startChar == ' ' || !std::isalnum(startChar)) {
                // if current character is a space or is not a letter,
                // then move to next character
                if (start > end) {
                    // handle all non-letter characters condition
                    return true;
                }
                startChar = s[start++];
            }

            char endChar = ' ';
            while (endChar == ' ' || !std::isalnum(endChar)) {
                // if current character is a space or is not a letter,
                // then move to previous character
                endChar = s[end--];
            }

            if (std::toupper(startChar) != std::toupper(endChar)) {
                isPalindrome = false;
                break;
            }
        }
        return isPalindrome;
    }
};


int main() {
    Solution s;
    std::cout << s.isPalindrome("A man, a plan, a canal: Panama")   // 1
              << std::endl;
    std::cout << s.isPalindrome("race a car") << std::endl;         // 0
    std::cout << s.isPalindrome(".,") << std::endl;                 // 1
    std::cout << s.isPalindrome("       ") << std::endl;            // 1
    std::cout << s.isPalindrome("ab") << std::endl;                 // 0
    std::cout << s.isPalindrome("OP") << std::endl;                 // 0
    std::cout << s.isPalindrome("b") << std::endl;                  // 1
    std::cout << s.isPalindrome("..&^*(a)*^&..,") << std::endl;     // 1
    std::cout << s.isPalindrome("1b1") << std::endl;                 // 1
    return 0;
}

