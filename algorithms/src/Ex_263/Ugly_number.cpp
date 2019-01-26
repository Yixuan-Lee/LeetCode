#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool isUgly(int num) {
        if (num == 1) {
            return true;
        }

        vector<int> primeFactors {2, 3, 5};

        while (num > 1) {
            int i = 0;
            for (i = 0; i < 3; i++) {
                if (num % primeFactors[i] == 0) {
                    num /= primeFactors[i];
                    break;
                }
            }
            if (i == 3) {
                break;
            }
        }

        return num == 1;
    }
};


int main() {
    Solution s;

    std::cout << s.isUgly(6) << std::endl;      // 1

    std::cout << s.isUgly(8) << std::endl;      // 1

    std::cout << s.isUgly(14) << std::endl;     // 0

    return 0;
}
