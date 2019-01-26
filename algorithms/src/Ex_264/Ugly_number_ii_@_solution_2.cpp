// references:
//      https://leetcode.com/submissions/detail/203781319/  (sample 0ms submission)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> ugly {1};
        static int idx2 = 0;
        static int idx3 = 0;
        static int idx5 = 0;
        while (ugly.size() < n) {
            int next2 = ugly[idx2] * 2;
            int next3 = ugly[idx3] * 3;
            int next5 = ugly[idx5] * 5;
            int next = std::min(next2, std::min(next3, next5));
            if (next2 == next) {
                idx2++;
            } else if (next3 == next) {
                idx3++;
            } else if (next5 == next) {
                idx5++;
            }
            if (ugly.back() == next) {
                continue;
            }
//            std::cout << next << ",";
            ugly.push_back(next);
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
