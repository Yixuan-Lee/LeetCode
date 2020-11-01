// references:
//      https://leetcode.com/problems/perfect-squares/discuss/226044/10-line-Java-BFS-solution


#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

class Solution {
public:
    int numSquares(int n) {
        queue<vector<int> > que;
        que.push(vector<int> {n, 0});
        while (!que.empty()) {
            vector<int> v = que.front();
            que.pop();
            for (int i = 1; i * i <= v[0]; i++) {
                if (v[0] == i * i) {
                    return v[1] + 1;
                }
                que.push(vector<int> {v[0] - i * i, v[1] + 1});
            }
        }
        return INT_MAX;
    }
};


int main() {
    Solution s;
    int n;

    n = 12;
    std::cout << s.numSquares(n) << std::endl;      // 3

    n = 13;
    std::cout << s.numSquares(n) << std::endl;      // 2

    n = 26;
    std::cout << s.numSquares(n) << std::endl;      // 2

    n = 51;
    std::cout << s.numSquares(n) << std::endl;      // 3

    return 0;
}
