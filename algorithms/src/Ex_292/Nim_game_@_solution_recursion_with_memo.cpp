#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canWinNim(int n) {
        memo = vector<bool>(n + 1, false);
        winlose = vector<bool>(n + 1, false);

        return canWinNim(n, true);
    }

private:
    vector<bool> memo;
    vector<bool> winlose;

    bool canWinNim(int curr, bool turn) {
        if (curr == 1 || curr == 2 || curr == 3) {
            return turn;
        }

        if (memo[curr]) {
            return winlose[curr];
        }

        bool factor3 = canWinNim(curr - 3, !turn);
        memo[curr - 3] = true;
        winlose[curr - 3] = factor3;

        bool factor2 = canWinNim(curr - 2, !turn);
        memo[curr - 2] = true;
        winlose[curr - 2] = factor2;

        bool factor1 = canWinNim(curr - 1, !turn);
        memo[curr - 1] = true;
        winlose[curr - 1] = factor1;

        return factor1 || factor2 || factor3;
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
