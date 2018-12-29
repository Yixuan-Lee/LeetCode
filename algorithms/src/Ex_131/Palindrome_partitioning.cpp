// references:
//      http://www.cplusplus.com/reference/string/string/substr/
//      https://leetcode.com/problems/palindrome-partitioning/discuss/42101/C%2B%2B-backtracking


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<vector<string>> partition(const string &s) {
        if (s.empty()) {
            return ans;
        }

        vector<string> per;
        partitioning(s, 0, per);
        return ans;
    }

private:
    vector<vector<string>> ans;

    void partitioning(const string &s, int start, vector<string> per) {
        auto n = static_cast<int> (s.length());

        if (start == n) {
            ans.push_back(per);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    per.push_back(s.substr(start, i - start + 1));
                    partitioning(s, i + 1, per);
                    per.pop_back();
                }
            }
        }
    }

    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};


// declare a template for overloading the << operator for vector<vector<<T>>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<vector<T>> &vec) {
    std::cout << "[" << std::endl;
    for (const vector<T> &v : vec) {
        std::cout << "\t[";
        for (const auto &i : v) {
            std::cout << i << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
//    vector<vector<string>>
//            res = s.partition("aab");
    vector<vector<string>>
            res = s.partition("aabcbaa");
    std::cout << res << std::endl;
    return 0;
}

