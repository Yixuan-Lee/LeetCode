#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long p = 1;
        for (int i = 0; p <= n; p *= 2) {
            if (p == n) {
                return true;
            }
        }

        return false;
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
