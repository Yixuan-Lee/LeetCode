#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        int r2;
        int xx = abs(x);
        while (xx > 0) {
            r2 = r2 * 10 + xx % 10;
            if ((r2 - xx % 10) / 10 != r)   // overflow
                return 0;
            else
                r = r2;
            xx /= 10;
        }
        if (x < 0)
            r = -r;
        return r;
    }
};

int main() {
    Solution s;
    int x;
    cin >> x;
    cout << s.reverse(x) << std::endl;
    return 0;
}
