//
// Created by  liyixuan on 2018-12-06.
//
// references:
//      https://blog.csdn.net/qq_38386316/article/details/76026451
//      book :《刘汝佳算法入门竞赛经典（第二版）》 —— 蛇形填数

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generateMatrix (int n) {
        if (n <= 0) {
            return vector<vector<int>>();
        }
        const int N = 100;
        int resArr[N][N];
        memset(resArr, 0, sizeof(resArr));
        int count = 0;
        int row = 0;
        int col = 0;
        resArr[row][col] = ++count;
        int endPoint = n * n;
        while (count < endPoint) {
            // go right
            while (col + 1 < n && !resArr[row][col + 1]) {
                resArr[row][++col] = ++count;
            }
            // go down
            while (row + 1 < n && !resArr[row + 1][col]) {
                resArr[++row][col] = ++count;
            }
            // go left
            while (col - 1 >= 0 && !resArr[row][col - 1]) {
                resArr[row][--col] = ++count;
            }
            // go up
            while (row - 1 >= 0 && !resArr[row - 1][col]) {
                resArr[--row][col] = ++count;
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            res.push_back(vector<int> {});
            for (int j = 0; j < n; j++) {
                res[i].push_back(resArr[i][j]);
            }
        }
        return res;
    }
};

// declare a template for overloading the << operator for vector<vector<<T>>
template<typename T>
std::ostream &operator<< (const std::ostream &output, const vector<T> &vec) {
    std::cout << "[" << std::endl;
    for (const vector<int> &v : vec) {
        std::cout << "\t[";
        for (const auto &i : v) {
            std::cout << i << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
}


int main () {
    Solution s;
    vector<vector<int>> res = s.generateMatrix(1);
    std::cout << res << std::endl;
    return 0;
}