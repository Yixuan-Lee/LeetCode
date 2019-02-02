// references:
//      https://jacksondunstan.com/articles/1946


#include <iostream>

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num <= 0) {
            return false;
        }

        int remainder = 0;
        while (num > 1 && remainder == 0) {
            remainder = num & 3;
            num = num >> 2;
        }

        return remainder == 0;
    }
};


int main() {
    Solution s;

    std::cout << s.isPowerOfFour(16) << std::endl;  // 1

    std::cout << s.isPowerOfFour(5) << std::endl;  // 0

    std::cout << s.isPowerOfFour(2) << std::endl;  // 0

    std::cout << s.isPowerOfFour(-2147483648) << std::endl;  // 0

    std::cout << s.isPowerOfFour(1) << std::endl;  // 1

    std::cout << s.isPowerOfFour(0) << std::endl;  // 0

    return 0;
}
