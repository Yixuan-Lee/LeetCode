#include <iostream>
#include <string>
#include <map>

using std::map;
using std::string;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() && t.empty()) {
            return true;
        } else if (s.empty()) {
            return false;
        } else if (t.empty()) {
            return false;
        }

        auto lengthOfS = static_cast<int> (s.length());
        auto lengthOfT = static_cast<int> (t.length());
        if (lengthOfS != lengthOfT) {
            return false;
        }

        map<char, int> hash4S;
        map<char, int> hash4T;

        for (const char &ch : s) {
            hash4S[ch]++;
        }
        for (const char &ch : t) {
            hash4T[ch]++;
        }

        for (auto &it : hash4S) {
            if (it.second != hash4T[it.first]) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution s;
    string s1;
    string s2;

    s1 = "anagram";
    s2 = "nagaram";
    std::cout << s.isAnagram(s1, s2) << std::endl;  // 1

    s1 = "rat";
    s2 = "car";
    std::cout << s.isAnagram(s1, s2) << std::endl;  // 0

    return 0;
}
