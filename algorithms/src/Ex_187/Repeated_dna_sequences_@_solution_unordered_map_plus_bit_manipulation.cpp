// references:
//      https://leetcode.com/submissions/detail/199349891/  (sample 32ms submission)


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
        if (s.size() <= 10) {
            return vector<string> {};
        }

        vector<string> ans;
        unordered_map<int, int> frequencies;

        int window = 0;
        int i;
        for (i = 0; i < 9; i++) {
            window = window * 4 + getValue(s[i]);
        }
        while (i < s.size()) {
            window = window * 4 + getValue(s[i++]);
            if (++frequencies[window] == 2) {
                ans.push_back(
                        s.substr(static_cast<unsigned long>(i - 10), 10));
            }
            // what does "<< 18" mean?
            window = window - (getValue(s[i - 10]) << 18);
        }

        return ans;
    }

private:
    int getValue(char c) {
        int value = -1;
        switch (c) {
            case 'A':
                value = 0;
                break;
            case 'C':
                value = 1;
                break;
            case 'G':
                value = 2;
                break;
            case 'T':
                value = 3;
                break;
        }
        return value;
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
