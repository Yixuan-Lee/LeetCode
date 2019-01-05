// references:
//      http://www.cplusplus.com/reference/cstdint/
//      https://en.wikipedia.org/wiki/Hamming_weight
//      https://helloacm.com/c-coding-exercise-number-of-1-bits-revisited/


#include <iostream>
#include <inttypes.h>

using std::uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // n & 1 means n % 2
        int r = n & 1;
//        std::cout << (n & 1) << ", " << n << std::endl;
        while (n >>= 1) {
            // n >>= 1 means n /= 2
//            std::cout << (n & 1) << ", " << n << std::endl;
            r += (n & 1);
        }
        return r;
    }
};


int main() {
    Solution s;
    uint32_t n;

    n = 00000000000000000000000000001011;
    std::cout << s.hammingWeight(n) << std::endl;       // 3

    return 0;
}
