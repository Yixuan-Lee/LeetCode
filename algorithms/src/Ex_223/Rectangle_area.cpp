// reference:
//      http://www.cnblogs.com/grandyang/p/4563153.html

#include <iostream>

using std::min;
using std::max;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // sum area of two rectangles
        int sum = (C - A) * (D - B) + (H - F) * (G - E);
        // if there is no overlap
        if ((E >= C)
            || (F >= D)
            || (B >= H)
            || (A >= G)) {
            return sum;
        }
        // if there is an overlap
        int overlap_length = min(C, G) - max(A, E); // x axis
        int overlap_width = min(D, H) - max(B, F); // y axis
        int overlap = overlap_length * overlap_width;
        sum = sum - overlap;
        return sum;
    }
};

int main() {
    Solution s;
    int A = -3;
    int B = 0;
    int C = 3;
    int D = 4;
    int E = 0;
    int F = -1;
    int G = 9;
    int H = 2;
    std::cout << s.computeArea(A, B, C, D, E, F, G, H) << std::endl;
    return 0;
}
