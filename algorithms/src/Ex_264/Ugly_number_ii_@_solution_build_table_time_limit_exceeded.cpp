#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    Solution() {
        const int MAX = 1690;
        vector<int> primeFactors {2, 3, 5};
        ugly.push_back(1);

        // build table from 2~MAX
        for (int i = 2;; i++) {
            int j;
            int temp = i;   // attention: don't use i directly to compute
            while (temp > 1) {
                for (j = 0; j < 3; j++) {
                    if (temp % primeFactors[j] == 0) {
                        temp /= primeFactors[j];
                        break;
                    }
                }
                if (j == 3) {
                    break;
                }
            }
            if (temp == 1) {
                ugly.push_back(i);
            }
//            std::cout << ugly.size() << std::endl;
            if (ugly.size() > MAX) {
                break;
            }
        }

    }

    int nthUglyNumber(int n) {
        // return nth ugly number
        return ugly[n - 1];
    }

private:
    vector<int> ugly;
};


int main() {
    Solution s;

    std::cout << s.nthUglyNumber(10) << std::endl;  // 12

    std::cout << s.nthUglyNumber(103) << std::endl;  // 1728

    return 0;
}
