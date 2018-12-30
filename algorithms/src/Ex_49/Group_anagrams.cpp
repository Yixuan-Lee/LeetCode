// references:
//      https://stackoverflow.com/questions/4951796/how-to-reverse-an-stdstring
//      http://www.cplusplus.com/reference/map/map/insert/


#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::vector;
using std::string;
using std::map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        if (strs.empty()) {
            return res;
        }

        map<string, vector<string>> anagrams;
        map<string, vector<string>>::iterator it;
        for (const string &s : strs) {
            string per = s;
            // sort the characters
            std::sort(per.begin(), per.end());
            it = anagrams.find(per);

            if (it != anagrams.end()) {
                // if found the the anagram string of s, add to the end
                it->second.push_back(s);
            } else {
                // if not found the anagram string of s, insert a new pair
                anagrams.insert(
                        std::pair<string, vector<string>>(
                                per,
                                vector<string> {
                                        s
                                }));
            }
        }

        for (it = anagrams.begin(); it != anagrams.end(); it++) {
            vector<string> per;
            for (std::vector<string>::iterator vit = it->second.begin();
                 vit != it->second.end(); vit++) {
                per.push_back(*vit);
            }
            res.push_back(per);
        }

        return res;
    }
};


int main() {
    Solution s;

    vector<string> input {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(input);

    std::cout << "[" << std::endl;
    for (const vector<string> &vec : res) {
        std::cout << "\t[";
        for (const string &str : vec) {
            std::cout << str << ",";
        }
        std::cout << "]," << std::endl << "";
    }
    std::cout << "]" << std::endl;
    return 0;
}
