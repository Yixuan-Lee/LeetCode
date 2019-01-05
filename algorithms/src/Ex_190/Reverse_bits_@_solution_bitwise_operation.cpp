// references:
//      https://leetcode.com/problems/reverse-bits/discuss/54746/Java-Solution-and-Optimization


#include <iostream>

using std::uint32_t;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = res + (n & 1);
            n >>= 1;
            if (i < 31) {
                res <<= 1;
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    uint32_t n;

    n = 00000010100101000001111010011100;
    std::cout << s.reverseBits(n)
              << std::endl;     // 964176192 (00111001011110000010100101000000)

    return 0;
}
