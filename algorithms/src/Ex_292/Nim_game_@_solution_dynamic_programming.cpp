// references:
//      https://leetcode.com/problems/nim-game/discuss/134338/Formal-way-of-dynamic-programming-(DP)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canWinNim(int n) {
        vector<bool> winlose(n + 1, false);
        winlose[1] = true;
        winlose[2] = true;
        winlose[3] = true;

        for (int i = 4; i <= n; i++) {
            winlose[i] = (
                    winlose[i - 1] == false || winlose[i - 2] == false
                    || winlose[i - 3] == false
            );
        }

        return winlose[n];
    }
};


int main() {
    Solution s;

    std::cout << s.canWinNim(5) << std::endl;       // 1

    std::cout << s.canWinNim(4) << std::endl;       // 0

    std::cout << s.canWinNim(64) << std::endl;      // 0

    std::cout << s.canWinNim(65) << std::endl;      // 1

    std::cout << s.canWinNim(66) << std::endl;      // 1

    std::cout << s.canWinNim(67) << std::endl;      // 1

    std::cout << s.canWinNim(68) << std::endl;      // 0

    return 0;
}
