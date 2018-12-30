// references:
//      https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/
//      https://longwayjade.wordpress.com/2015/05/06/leetcode-binary-search-math-powx-n/
//      https://leetcode.com/problems/powx-n/discuss/194061/C%2B%2B-Easy-and-Short-Solution-that-passes-all-tests


#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
//            x = 1 / x;
//            n = -n;

            // = (1/x) * (1/x)^-1 * pow(1/x, -n) = pow(x, n)
            return 1 / x * myPow(1 / x, -(n + 1));
        }
        double temp = myPow(x, n / 2);
        return n % 2 == 0 ? temp * temp : x * temp * temp;
    }
};

int main() {
    Solution s;
    double x = 34.00515;
    int n = -3;
    std::cout << s.myPow(x, n) << std::endl;
    return 0;
}
