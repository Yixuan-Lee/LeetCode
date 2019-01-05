// references:
//      http://www.cplusplus.com/reference/cstdint/
//      https://en.wikipedia.org/wiki/Hamming_weight
//      https://helloacm.com/c-coding-exercise-number-of-1-bits-revisited/
//      https://stackoverflow.com/questions/43028865/how-to-print-hex-from-uint32-t
//      https://stackoverflow.com/questions/12120426/how-do-i-print-uint32-t-and-uint16-t-variables-value


#include <iostream>
#include <inttypes.h>

using std::uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int r = n ? 1 : 0;
        printf("%" PRIu32 "\n", n);         // for debugging
        while (n &= (n - 1)) {
            printf("%08" PRIx32 "\n", n);   // for debugging, print in hex

            // n & (n - 1), remove the least-significant 1
            // remove 1 until the number n becomes 0
            r++;
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
