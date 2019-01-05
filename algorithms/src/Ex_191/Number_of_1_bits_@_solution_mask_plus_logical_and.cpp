// references:
//      https://leetcode.com/articles/number-1-bits/


#include <iostream>

using std::uint32_t;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        int mask = 1;   // 0000 0000 0000 0000 0000 0000 0000 0001
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                bits++;
            }
            mask <<= 1;     // shift the mask to the left by one
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
