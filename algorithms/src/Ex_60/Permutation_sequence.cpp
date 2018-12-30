#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> chars;
        for (int i = 1; i <= n; i++) {
            chars.push_back(static_cast<char &&> ('0' + i));
        }
        vector<char> per;
        backtracking(n, k, chars, per);
        return res;
    }

private:
    string res;
    int currentK {};

    void backtracking(int n, int k, vector<char> &chars, vector<char> &per) {
        if (per.size() == chars.size()) {
            currentK++;
            if (currentK == k) {
                for (const char &c : per) {
                    res += c;
                }
            }
            return;
        }
        auto size = static_cast<int>(chars.size());
        for (int i = 0; i < size; i++) {
            // speed up returning
            if (currentK == k) {
                return;
            }
            // if per has chars[i], then try the next character
            if (std::find(per.begin(), per.end(), chars[i]) != per.end()) {
                continue;
            }
            per.push_back(chars[i]);
            backtracking(n, k, chars, per);
            per.pop_back();
        }
    }
};


int main() {
    Solution s;
    string res = s.getPermutation(9, 136371);
    std::cout << res << std::endl;
    return 0;
}
