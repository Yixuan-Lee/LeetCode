// references:
//      https://leetcode.com/submissions/detail/198560314/ (sample 0ms submission)


#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::queue;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        queue<int> q1;
        queue<int> q2;
        string temp;
        // push all numbers in version1 to the q1
        for (int i = 0; i < version1.size(); i++) {
            if (version1[i] != '.') {
                temp += version1[i];
            }
            if (version1[i] == '.' || i == version1.size() - 1) {
                q1.push(stoi(temp));
                temp = "";
            }
        }
        // push all numbers in version2 to the q2
        for (int i = 0; i < version2.size(); i++) {
            if (version2[i] != '.') {
                temp += version2[i];
            }
            if (version2[i] == '.' || i == version2.size() - 1) {
                q2.push(stoi(temp));
                temp = "";
            }
        }

        while (!q1.empty() || !q2.empty()) {
            int v1 = 0;     // initialize and filter the trailing 0
            int v2 = 0;     // initialize and filter the trailing 0
            if (!q1.empty()) {
                v1 = q1.front();
                q1.pop();
            }
            if (!q2.empty()) {
                v2 = q2.front();
                q2.pop();
            }
            if (v1 < v2) {
                return -1;
            } else if (v1 > v2) {
                return 1;
            }
        }

        return 0;
    }
};


int main() {
    Solution s;

    std::cout << s.compareVersion("0.1", "1.1") << std::endl;           // -1

    std::cout << s.compareVersion("1.0.1", "1") << std::endl;           // 1

    std::cout << s.compareVersion("7.5.2.4", "7.5.3") << std::endl;     // -1

    std::cout << s.compareVersion("01", "1") << std::endl;              // 0

    std::cout << s.compareVersion("1.0", "1") << std::endl;             // 0

    std::cout << s.compareVersion("1.1", "1") << std::endl;             // 1

    return 0;
}
