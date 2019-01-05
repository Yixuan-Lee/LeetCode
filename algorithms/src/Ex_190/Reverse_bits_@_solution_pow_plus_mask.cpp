// references:
//      https://community.particle.io/t/how-to-convert-string-to-uint32-t/36362/3


#include <iostream>
#include <cmath>

using std::uint32_t;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int mask = 1;
        auto feed = static_cast<uint32_t> (pow(2, 31));
        for (int i = 0; i < 32; i++) {
            if ((n & mask) != 0) {
                ans += feed;
            }
            mask <<= 1;
            feed >>= 1;
        }

        return ans;
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
