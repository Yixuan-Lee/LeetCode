// references:
//      https://leetcode.com/problems/simplify-path/discuss/200362/C%2B%2B-stack-solution


#include <iostream>
#include <sstream>  // istringstream
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    string simplifyPath(const string &path) {
        // convert string into stream
        std::istringstream ss(path);

        vector<string> stack;
        string tempPath;
        while (getline(ss, tempPath, '/')) {
//            std::cout << tempPath << std::endl;
            if (tempPath == "." || tempPath.empty()) {
                continue;
            } else if (tempPath == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else {
                stack.push_back(tempPath);
            }
        }

        string res;
        for (auto &s : stack) {
            res += "/" + s;
        }

        return res.empty() ? "/" : res;
    }
};


int main() {
    Solution s;
    std::cout << s.simplifyPath("/a//b////c/d//././/..") << std::endl;
    return 0;
}
