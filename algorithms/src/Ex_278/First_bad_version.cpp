// references:
//      https://leetcode.com/articles/first-bad-version/


#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long lo = 1;    // using long to avoid overflow
        long hi = n;
        while (lo < hi) {
            long mid = (lo + hi) / 2;
            if (isBadVersion(mid) == false) {
                lo = mid + 1;
            } else {
                // mid may or may not be the first bad version
                hi = mid;
            }
        }

        return static_cast<int> (lo);
    }
};


int main() {
    Solution s;

    return 0;
}
