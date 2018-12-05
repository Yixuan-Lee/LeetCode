//
// Created by  liyixuan on 2018-12-03.
//
// references:
//      https://stackoverflow.com/questions/2448380/c-expected-constant-expression
//      https://stackoverflow.com/questions/1946830/multidimensional-variable-size-array-in-c
//      https://blog.csdn.net/qq_38386316/article/details/76026451
//      book :《刘汝佳算法入门竞赛经典（第二版）》 —— 蛇形填数

#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder (vector<vector<int>> &matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }

        const auto rows = static_cast<int>(matrix.size());
        const auto cols = static_cast<int>(matrix[0].size());
        // declare flag for each position
        bool **flag = new bool *[rows];  // each element is a pointer to an array
        for (size_t i = 0; i < rows; i++) {
            flag[i] = new bool[cols]; // build rows
            for (size_t j = 0; j < cols; j++) {
                flag[i][j] = true;
            }
        }

        int i = 0;  // row
//        int j = -1;  // column
        int j = 0;
        res.push_back(matrix[i][j]);
        flag[i][j] = false;
        while (allFalseInFlag(flag, rows, cols)) {
            // go right
//            while (j < cols - 1 && flag[i][++j]) {
            while (j + 1 < cols && flag[i][j + 1]) {
                res.push_back(matrix[i][++j]);
                flag[i][j] = false;
            }
            // go down
//            while (i < rows - 1 && flag[++i][j]) {
            while (i + 1 < rows && flag[i + 1][j]) {
                res.push_back(matrix[++i][j]);
                flag[i][j] = false;
            }
            // go left
//            while (j > 0 && flag[i][j--]) {
            while (j > 0 && flag[i][j - 1]) {
                res.push_back(matrix[i][--j]);
                flag[i][j] = false;
            }
            // go up
//            while (i > 0 && flag[i--][j]) {
            while (i > 0 && flag[i - 1][j]) {
                res.push_back(matrix[--i][j]);
                flag[i][j] = false;
            }
        }

        // free the flag resources
        for (size_t k = 0; k < rows; k++) {
            delete flag[k];
        }
        delete flag;

        return res;
    }

private:
    bool allFalseInFlag (bool **flag, const int rows, const int cols) {
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < cols; j++) {
                if (flag[i][j]) {
                    return true;    // keep looping
                }
            }
        }
        return false;   // all flags are false, stop looping
    }
};

// declare a template for overloading the << operator for vector<int>
template<typename T>
std::ostream &operator<< (std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}


int main () {
    Solution s;
    vector<vector<int>> input = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    vector<int> res = s.spiralOrder(input);
    std::cout << res << std::endl;
    return 0;
}