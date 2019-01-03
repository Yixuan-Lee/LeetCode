#include <iostream>
#include <string>
#include <cmath>

using std::string;

class Solution {
public:
    int titleToNumber(string s) {
        auto size = static_cast<int> (s.size());
        reverse(s.begin(), s.end());
        int ans = 0;
        for (int i = 0; i < size; i++) {
            ans += (s[i] - 'A' + 1) * static_cast<int> (pow(26, i));
        }
        return ans;
    }
};


int main() {
    Solution s;

    std::cout << s.titleToNumber("A") << std::endl;     // 1

    std::cout << s.titleToNumber("AB") << std::endl;    // 28

    std::cout << s.titleToNumber("ZY") << std::endl;    // 701

    return 0;
}
