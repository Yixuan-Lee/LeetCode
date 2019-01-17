#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        }
        if (n <= 0) {
            return false;
        }

        while (n > 1) {
            if (n % 2 == 0) {
                n >>= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};


int main() {
    Solution s;

    std::cout << s.isPowerOfTwo(1) << std::endl;        // 1

    std::cout << s.isPowerOfTwo(16) << std::endl;       // 1

    std::cout << s.isPowerOfTwo(218) << std::endl;      // 0

    std::cout << s.isPowerOfTwo(64) << std::endl;       // 1

    std::cout << s.isPowerOfTwo(256) << std::endl;      // 1

    std::cout << s.isPowerOfTwo(616) << std::endl;      // 0

    std::cout << s.isPowerOfTwo(0) << std::endl;        // 0

    return 0;
}
