#include <iostream>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        for (int i = m + 1; i <= n; i++) {
            m &= i;
        }
        return m;
    }
};


int main() {
    Solution s;
    std::cout << s.rangeBitwiseAnd(5, 7) << std::endl;      // 4
    std::cout << s.rangeBitwiseAnd(0, 1) << std::endl;      // 0
    return 0;
}
