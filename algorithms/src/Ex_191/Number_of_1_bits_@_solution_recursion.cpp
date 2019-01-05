// references:
//      http://www.cplusplus.com/reference/cstdint/
//      https://en.wikipedia.org/wiki/Hamming_weight
//      https://helloacm.com/c-coding-exercise-number-of-1-bits-revisited/


#include <iostream>

using std::uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
//        std::cout << n << ", " << (n & 1) << std::endl;

        // n & 1 equals to n % 2    (more efficient)
        // n >> 1 equals to n /= 2  (faster)
        return (n & 1) + (n == 0 ? 0 : hammingWeight(n >> 1));
    }
};


int main() {
    Solution s;
    uint32_t n;

    n = 00000000000000000000000000001011;
    std::cout << s.hammingWeight(n) << std::endl;       // 3

    return 0;
}
