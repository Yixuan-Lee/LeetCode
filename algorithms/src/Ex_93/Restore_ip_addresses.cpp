#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> restoreIpAddresses(const string &s) {
        if (s.length() < 4) {
            return ans;
        }

        vector<string> combi;
        backtracking(s, combi, 0);
        return ans;
    }

private:
    vector<string> ans;

    void backtracking(const string &s, vector<string> combi,
            int currIndex) {
        if (combi.size() == 4) {
            if (currIndex == s.size()) {
                ans.push_back(
                        combi[0] + "." + combi[1] + "." + combi[2] + "."
                        + combi[3]);
            }
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (currIndex + i > s.size()) {
                // avoid index out of range
                continue;
            }
            string temp = s.substr(currIndex, i);
            if (i > 1 && temp[0] == '0') {
                // avoid like "010.0.1.0"
                continue;
            }
            if (std::stoi(temp) <= 255) {
                combi.push_back(temp);
                backtracking(s, combi, currIndex + i);
                combi.pop_back();   // backtracking
            }
        }
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
//    vector<string> res = s.restoreIpAddresses("25525511135");
    vector<string> res = s.restoreIpAddresses("010010");
    std::cout << res << std::endl;
    return 0;
}

