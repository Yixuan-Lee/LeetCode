#include <iostream>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if (n == 1) {
            return isBadVersion(n);
        }

        int lo = 2;
        int hi = n;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (isBadVersion(mid) && isBadVersion(mid - 1) == false) {
                return mid;
            }
            if (isBadVersion(mid) == false) {
                // meaning that [1...mid] are good products
                lo = mid + 1;
            } else {
                // meaning that product mid is bad
                hi = mid - 1;
            }
        }

        return 1;
    }
};


int main() {
    Solution s;

    return 0;
}
