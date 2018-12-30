// references:
//      https://leetcode.com/problems/generate-parentheses/solution/
//      https://stackoverflow.com/questions/14737078/how-to-copy-a-stack
//      http://www.cplusplus.com/forum/beginner/149957/


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) {
            return res;
        }
        backtracking(res, "", 0, 0, n);
        return res;
    }

private:
    void
    backtracking(vector<string> &res, const string &curr, int openNum,
            int closeNum, int n) {
        if (curr.length() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (openNum < n) {
            backtracking(res, curr + "(", openNum + 1, closeNum, n);
        }
        if (openNum > closeNum) {
            backtracking(res, curr + ")", openNum, closeNum + 1, n);
        }
    }
};


int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (const string &str : res) {
        std::cout << str << std::endl;
    }
    return 0;
}
