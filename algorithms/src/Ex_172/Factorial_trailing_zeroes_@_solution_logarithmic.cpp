// references:
//      https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52367/My-explanation-of-the-Log(n)-solution


#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        int countFive = 0;
        long divider = 5;   // here needs long type
        while (n / divider > 0) {
            countFive += n / divider;
            divider *= 5;
        }
        return countFive;
    }
};


int main() {
    Solution s;

    std::cout << s.trailingZeroes(3) << std::endl;              // 0

    std::cout << s.trailingZeroes(5) << std::endl;              // 1

    std::cout << s.trailingZeroes(10) << std::endl;             // 2

    std::cout << s.trailingZeroes(30) << std::endl;             // 7

    std::cout << s.trailingZeroes(50) << std::endl;             // 12

    std::cout << s.trailingZeroes(1808548329) << std::endl;     // 452137076

    return 0;
}
