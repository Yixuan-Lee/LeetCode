// references:
//      https://leetcode.com/articles/power-of-three/
//      https://www.quora.com/How-do-I-check-if-a-number-is-integer-on-C++#


#include <iostream>
#include <cmath>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        double res = log10(n) / log10(3);
        return floor(res) == res;
    }
};


int main() {
    Solution s;

    std::cout << s.isPowerOfThree(27) << std::endl;     // 1

    std::cout << s.isPowerOfThree(0) << std::endl;      // 0

    std::cout << s.isPowerOfThree(1) << std::endl;      // 1

    return 0;
}
