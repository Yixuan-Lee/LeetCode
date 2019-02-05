#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string reverseVowels(string s) {
        auto length = static_cast<int> (s.length());
        int left = 0;
        int right = length - 1;
        bool leftVowel = false;
        bool rightVowel = false;
        while (left < right) {
            if (isVowels(s[left])) {
                leftVowel = true;
            }
            if (isVowels(s[right])) {
                rightVowel = true;
            }
            if (leftVowel && rightVowel) {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                leftVowel = false;
                rightVowel = false;
            }
            if (!leftVowel) {
                left++;
            }
            if (!rightVowel) {
                right--;
            }
        }

        return s;
    }

private:
    bool isVowels(const char &ch) {
        return ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i'
               || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u'
               || ch == 'U';
    }
};


int main() {
    Solution s;

    std::cout << s.reverseVowels("hello") << std::endl;         // "holle"

    std::cout << s.reverseVowels("leetcode") << std::endl;      // "leotcede"
    return 0;
}
