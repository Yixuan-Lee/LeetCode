// references:
//      https://leetcode.com/articles/number-1-bits/


#include <iostream>

using std::uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        while (n != 0) {
            bits++;
            // do a bit-wise logical and with (n-1) to flip the least-significant 1-bit in n to 0
            //
            // "least-significant 1-bit in n" means the right-most 1 in n
            // n - 1 will replace the right-most 1 to 1s at the right of the position of right-most 1
            // so n & (n - 1) will always remove the right-most 1 in current n
            n = n & (n - 1);
        }
        return bits;
    }
};


int main() {
    Solution s;
    uint32_t n;

    n = 00000000000000000000000000001011;
    std::cout << s.hammingWeight(n) << std::endl;       // 3

    return 0;
}
