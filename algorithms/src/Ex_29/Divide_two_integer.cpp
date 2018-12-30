#include <iostream>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return overflow;
        }
        long res = (long) dividend / divisor;
        if (res < -pow(2, 31) || res > pow(2, 31) - 1) {
            return overflow;
        }
        return static_cast<int>(res);
    }

private:
    const int overflow = static_cast<int> (pow(2, 31) - 1);
};

int main() {
    Solution s;
    int diviend = -2147483648, divisor = -1;
    std::cout << s.divide(diviend, divisor) << std::endl;
    return 0;
}
