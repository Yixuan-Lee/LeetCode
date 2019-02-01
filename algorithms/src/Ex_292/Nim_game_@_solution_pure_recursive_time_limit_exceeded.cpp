#include <iostream>
#include <vector>

class Solution {
public:
    bool canWinNim(int n) {
        return canWinNim(n, true);
    }

private:
    bool canWinNim(int curr, bool turn) {
        if (curr == 1 || curr == 2 || curr == 3) {
            return turn;
        }

        return canWinNim(curr - 1, !turn) || canWinNim(curr - 2, !turn)
               || canWinNim(curr - 3, !turn);
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
