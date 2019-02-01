#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool canWinNim(int n) {
        memo = vector<bool>(n + 1, false);
        winlose = vector<bool>(n + 1, false);
        memo[1] = true;
        memo[2] = true;
        memo[3] = true;
        winlose[1] = true;
        winlose[2] = true;
        winlose[3] = true;
        return canWinNim(n, true);
    }

private:
    vector<bool> memo;
    vector<bool> winlose;

    bool canWinNim(int curr, bool turn) {
        if (memo[curr]) {
            return winlose[curr] && turn;
        }

        bool factor1 = canWinNim(curr - 1, !turn);

        bool factor2 = canWinNim(curr - 2, !turn);

        bool factor3 = canWinNim(curr - 3, !turn);

        memo[curr] = true;
        winlose[curr] = factor1 || factor2 || factor3;

        return winlose[curr];
    }
};


int main() {
    Solution s;

    std::cout << s.canWinNim(4) << std::endl;   // 0

    std::cout << s.canWinNim(5) << std::endl;   // 1

    std::cout << s.canWinNim(8) << std::endl;   // 0

    std::cout << s.canWinNim(64) << std::endl;   // 0

    std::cout << s.canWinNim(65) << std::endl;   // 1

    std::cout << s.canWinNim(66) << std::endl;   // 1

    std::cout << s.canWinNim(67) << std::endl;   // 1

    std::cout << s.canWinNim(68) << std::endl;   // 0

    return 0;
}
