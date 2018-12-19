// references:
//      https://leetcode.com/problems/unique-paths/discuss/204632/topic


#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        totalX = m;
        totalY = n;
        goTo(0, 0);
        return ans;
    }

    void goTo(int startX, int startY) {
        if (startX == totalX - 1 && startY == totalY - 1) {
            ans += 1;
        } else {
            if (startX < totalX && startY < totalY) {
                // go right
                goTo(startX, startY + 1);
                // go down
                goTo(startX + 1, startY);
            }
        }
    }

private:
    int ans;
    int totalX;
    int totalY;
};


int main() {
    Solution s;
    std::cout << s.uniquePaths(3, 2) << std::endl;
    return 0;
}