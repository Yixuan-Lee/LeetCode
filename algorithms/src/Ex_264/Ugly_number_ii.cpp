#include <iostream>

class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[1960];
        ugly[0] = 1;

        int currIdx = 1;    // current index where i will write to ugly array
        int prev2Idx = 0;   // previous index for multiplying 2
        int prev3Idx = 0;   // previous index for multiplying 3
        int prev5Idx = 0;   // previous index for multiplying 5
        while (currIdx < n) {
            if (ugly[prev2Idx] * 2 <= ugly[prev3Idx] * 3
                && ugly[prev2Idx] * 2 <= ugly[prev5Idx] * 5) {
                // avoid repetition
                if (ugly[currIdx - 1] == ugly[prev2Idx] * 2) {
                    prev2Idx++;
                    continue;
                }
                ugly[currIdx++] = ugly[prev2Idx] * 2;
                prev2Idx++;
            } else if (ugly[prev3Idx] * 3 < ugly[prev2Idx] * 2
                       && ugly[prev3Idx] * 3 <= ugly[prev5Idx] * 5) {
                // avoid repetition
                if (ugly[currIdx - 1] == ugly[prev3Idx] * 3) {
                    prev3Idx++;
                    continue;
                }
                ugly[currIdx++] = ugly[prev3Idx] * 3;
                prev3Idx++;
            } else if (ugly[prev5Idx] * 5 < ugly[prev2Idx] * 2
                       && ugly[prev5Idx] * 5 < ugly[prev3Idx] * 3) {
                // avoid repetition
                if (ugly[currIdx - 1] == ugly[prev5Idx] * 5) {
                    prev5Idx++;
                    continue;
                }
                ugly[currIdx++] = ugly[prev5Idx] * 5;
                prev5Idx++;
            }
//            std::cout << currIdx << ": " << ugly[currIdx - 1] << std::endl;
        }

        return ugly[n - 1];
    }
};


int main() {
    Solution s;

    std::cout << s.nthUglyNumber(10) << std::endl;      // 12

    std::cout << s.nthUglyNumber(103) << std::endl;     // 1728

    return 0;
}
