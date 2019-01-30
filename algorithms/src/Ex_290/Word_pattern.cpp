// references:
//      https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c


#include <iostream>
#include <string>
#include <vector>
#include <map>

using std::map;
using std::vector;
using std::string;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, vector<int>> patternHash;
        map<int, string> strHash;
        for (int i = 0; i < pattern.length(); i++) {
            patternHash[pattern[i]].push_back(i);
        }

        string delimiter = " ";
        string token;
        int pos = 0;
        int index = 0;
        while ((pos = str.find(delimiter)) != string::npos) {
            strHash[index++] = str.substr(0, pos);
            str.erase(0, pos + delimiter.length());
        }
        strHash[index] = str;

        // length of pattern is not same as number of strings
        if (pattern.length() != index + 1) {
            return false;
        }

        // check same character corresponding to same string
        for (auto &it : patternHash) {
            string comp = strHash[it.second[0]];
            for (const int &i : it.second) {
                if (strHash[i] != comp) {
                    return false;
                }
            }
        }

        // check different character corresponding to different string
        for (auto &it1 : patternHash) {
            for (auto &it2 : patternHash) {
                if (it1.first == it2.first) {
                    continue;
                } else {
                    if (strHash[it1.second[0]] == strHash[it2.second[0]]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};


int main() {
    Solution s;

    std::cout << s.wordPattern("abba", "dog cat cat dog") << std::endl;   // 1

    std::cout << s.wordPattern("abba", "dog cat cat fish") << std::endl;  // 0

    std::cout << s.wordPattern("aaaa", "dog cat cat dog") << std::endl;   // 0

    std::cout << s.wordPattern("aaaa", "dog dog dog dog") << std::endl;   // 1

    std::cout << s.wordPattern("abba", "dog dog dog dog") << std::endl;   // 0

    std::cout << s.wordPattern("aaa", "dog dog dog dog") << std::endl;    // 0

    return 0;
}
