// references:
//      https://leetcode.com/problems/bitwise-and-of-numbers-range/discuss/211810/C%2B%2B-O(32)-shift


#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            count++;
        }

        return (m <<= count);
    }
};


int main() {
    Solution s;
    std::cout << s.rangeBitwiseAnd(5, 7) << std::endl;              // 4
    std::cout << s.rangeBitwiseAnd(0, 1) << std::endl;              // 0
    std::cout << s.rangeBitwiseAnd(1, 2) << std::endl;              // 0
    std::cout << s.rangeBitwiseAnd(1, 3) << std::endl;              // 0
    std::cout << s.rangeBitwiseAnd(0, 2147483647) << std::endl;     // 0
    std::cout << s.rangeBitwiseAnd(1, 2147483647) << std::endl;     // 0
    return 0;
}
