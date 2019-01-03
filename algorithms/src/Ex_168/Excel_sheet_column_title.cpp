// references:
//      https://leetcode.com/problems/excel-sheet-column-title/discuss/210705/Java-one-line-recursive-and-iterative-both-0ms-100


#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            n--;
            ans += static_cast<char> (n % 26 + 'A');
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    Solution s;

    std::cout << s.convertToTitle(1) << std::endl;      // A

    std::cout << s.convertToTitle(26) << std::endl;     // Z

    std::cout << s.convertToTitle(27) << std::endl;     // AA

    std::cout << s.convertToTitle(28) << std::endl;     // AB

    std::cout << s.convertToTitle(701) << std::endl;    // ZY

    std::cout << s.convertToTitle(703) << std::endl;    // AAA
    return 0;
}
