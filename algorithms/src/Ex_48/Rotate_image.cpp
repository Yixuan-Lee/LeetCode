//
// Created by  liyixuan on 2018-12-02.
//
// references:
//      https://leetcode.com/problems/rotate-image/discuss/18879/AC-Java-in-place-solution-with-explanation-Easy-to-understand.


#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    void rotate (vector<vector<int>> &matrix) {
        if (matrix.size() <= 1) {
            return;
        }
        int size = static_cast<int>(matrix.size());

        // transpose the matrix
        // swap (matrix[i][j], matrix[j][i])
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        // rotate the matrix
        // swap (matrix[i][j], matrix[i][size - 1 - j])
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size / 2; j++) {
                std::swap(matrix[i][j], matrix[i][size - 1 - j]);
            }
        }
    }
};


int main () {
    Solution s;
    vector<vector<int>> input {
            {15, 13, 2,  5},
            {14, 3,  4,  1},
            {12, 6,  8,  9},
            {16, 7,  10, 11},
    };

    s.rotate(input);

    std::cout << "[" << std::endl;
    for (const vector<int> &v : input) {
        std::cout << "\t[";
        for (const int &i : v) {
            std::cout << i << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return 0;
}