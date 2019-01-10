#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty() && t.empty()) {
            return true;
        }
        if (s.empty() || t.empty()) {
            return false;
        }

        auto lengthS = static_cast<int> (s.size());
        auto lengthT = static_cast<int> (t.size());
        if (lengthS != lengthT) {
            return false;
        }

        bool s2t;
        bool t2s;
        // try s -> t
        map<char, char> hash;
        string copyS = s;
        for (int i = 0; i < lengthS; i++) {
            if (hash.find(copyS[i]) == hash.end()) {
                hash[copyS[i]] = t[i];
                copyS[i] = hash[copyS[i]];
            } else {
                copyS[i] = hash[copyS[i]];
            }
        }
        s2t = (copyS == t);

        // try t -> s
        hash.clear();
        string copyT = t;
        for (int i = 0; i < lengthT; i++) {
            if (hash.find(copyT[i]) == hash.end()) {
                hash[copyT[i]] = s[i];
                copyT[i] = hash[copyT[i]];
            } else {
                copyT[i] = hash[copyT[i]];
            }
        }
        t2s = (copyT == s);

        return s2t && t2s;
    }
};


int main() {
    Solution s;
    string ss;
    string tt;

    ss = "egg";
    tt = "add";
    std::cout << s.isIsomorphic(ss, tt) << std::endl;   // 1

    ss = "foo";
    tt = "bar";
    std::cout << s.isIsomorphic(ss, tt) << std::endl;   // 0

    ss = "paper";
    tt = "title";
    std::cout << s.isIsomorphic(ss, tt) << std::endl;   // 1

    ss = "bar";
    tt = "foo";
    std::cout << s.isIsomorphic(ss, tt) << std::endl;   // 0

    return 0;
}
