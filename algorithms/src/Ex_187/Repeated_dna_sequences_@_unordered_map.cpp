#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::vector;
using std::string;
using std::unordered_map;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(const string &s) {
        vector<string> ans;
        auto length = static_cast<int> (s.size());
        if (length < 10) {
            return ans;
        }

        // store occurance time for all 10-letter-long sequences
        unordered_map<string, int> hash;
        for (int i = 0; i <= length - 10; i++) {
            string sub = s.substr(static_cast<unsigned long> (i), 10);
            if (hash.find(sub) == hash.end()) {
                hash[sub] = 1;
            } else {
                hash[sub]++;
            }
        }

        // push all string that occurs more than once to the returned vector
        for (auto &it : hash) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};


void print(const vector<string> &res) {
    std::cout << "[";
    for (const string &s : res) {
        std::cout << s << ",";
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution s;
    string input;
    vector<string> res;

    input = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    res = s.findRepeatedDnaSequences(input);
    print(res);

    input = "AAAAAAAAAAA";
    res = s.findRepeatedDnaSequences(input);
    print(res);

    return 0;
}
