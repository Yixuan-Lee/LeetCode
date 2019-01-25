#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        int sum = 10;
        while (sum >= 10) {
            sum = 0;
            sum = getFinalSum(sum, num);
            num = sum;
        }

        return sum;
    }

private:
    int getFinalSum(int &sum, int &num) {
        if (num == 0) {
            return sum;
        }

        sum += num % 10;
        num /= 10;
        return getFinalSum(sum, num);
    }
};


int main() {
    Solution s;

    std::cout << s.addDigits(38) << std::endl;      // 2

    return 0;
}
