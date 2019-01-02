#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int idx1 = 0;
        int idx2 = 0;
        auto size1 = static_cast<int> (version1.size());
        auto size2 = static_cast<int> (version2.size());
        int num1;
        int num2;
        while (idx1 < size1 && idx2 < size2) {
            string temp;
            while (idx1 < size1 && version1[idx1] != '.') {
                temp += version1[idx1];
                idx1++;
            }
            idx1++;     // move to the start position of next number
            num1 = stoi(temp);

            temp = "";
            while (idx2 < size2 && version2[idx2] != '.') {
                temp += version2[idx2];
                idx2++;
            }
            idx2++;     // move to the start position of next number
            num2 = stoi(temp);

            if (num1 == num2) {
                continue;
            } else if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
        }
        if (idx1 < size1) {
            while (idx1 < size1 &&
                   (version1[idx1] == '.' || version1[idx1] == '0')) {
                // filter the trailing 0 and '.'
                idx1++;
            }
            if (idx1 < size1) {
                return 1;
            } else {
                return 0;
            }
        }
        if (idx2 < size2) {
            while (idx2 < size2 &&
                   (version2[idx2] == '.' || version2[idx2] == '0')) {
                // filter the trailing 0 and '.'
                idx2++;
            }
            if (idx2 < size2) {
                return -1;
            } else {
                return 0;
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

    return 0;
}
