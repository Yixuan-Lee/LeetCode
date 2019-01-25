#include <iostream>

class Solution {
public:
    int addDigits(int num) {
        int sum = 10;
        while (sum >= 10) {
            int newSum = 0;
            while (num > 0) {
                newSum += num % 10;
                num /= 10;
            }
            sum = newSum;
            num = sum;
        }

        return sum;
    }
};


int main() {
    Solution s;

    std::cout << s.addDigits(38) << std::endl;      // 2

    return 0;
}
