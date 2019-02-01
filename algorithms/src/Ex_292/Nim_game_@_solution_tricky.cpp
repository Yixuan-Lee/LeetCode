// references:
//      https://leetcode.com/articles/nim-game/


#include <iostream>

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4 != 0);
    }
};


int main() {
    Solution s;

    std::cout << s.canWinNim(4) << std::endl;   // 0

    std::cout << s.canWinNim(5) << std::endl;   // 1

    std::cout << s.canWinNim(64) << std::endl;   // 0

    std::cout << s.canWinNim(65) << std::endl;   // 1

    std::cout << s.canWinNim(66) << std::endl;   // 1

    std::cout << s.canWinNim(67) << std::endl;   // 1

    std::cout << s.canWinNim(68) << std::endl;   // 0

    return 0;
}
