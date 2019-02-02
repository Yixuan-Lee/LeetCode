#include <iostream>
#include <vector>

using std::vector;

class NumMatrix {
public:
    explicit NumMatrix(const vector<vector<int>> &matrix) {
        auto rows = static_cast<int> (matrix.size());
        if (rows == 0) {
            return;
        }
        auto cols = static_cast<int> (matrix[0].size());

        sums = vector<vector<int>>(rows, vector<int>(cols, 0));
        sums[0][0] = matrix[0][0];

        // set values to the first row
        for (int i = 1; i < cols; i++) {
            sums[0][i] = sums[0][i - 1] + matrix[0][i];
        }
        // set values to the first column
        for (int j = 1; j < rows; j++) {
            sums[j][0] = sums[j - 1][0] + matrix[j][0];
        }
        // set values to other positions
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                sums[i][j] = sums[i - 1][j] + sums[i][j - 1]
                             - sums[i - 1][j - 1] + matrix[i][j];
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sums.empty()) {
            return 0;
        }

        if (row2 == 0) {
            // return values from col1~col2 on row 0
            if (col1 != 0) {
                return sums[0][col2] - sums[0][col1 - 1];
            } else {
                return sums[0][col2];
            }
        }

        if (col2 == 0) {
            // return values from row1~row2 on column 0
            if (row1 != 0) {
                return sums[row2][0] - sums[row1 - 1][0];
            } else {
                return sums[row2][0];
            }
        }

        if (row1 == 0) {
            if (col1 == 0) {
                return sums[row2][col2];
            } else {
                return sums[row2][col2] - sums[row2][col1 - 1];
            }
        }

        if (col1 == 0) {
            if (row1 == 0) {
                return sums[row2][col2];
            } else {
                return sums[row2][col2] - sums[row1 - 1][col2];
            }
        }

        return sums[row2][col2] - sums[row2][col1 - 1] - sums[row1 - 1][col2]
               + sums[row1 - 1][col1 - 1];
    }

private:
    // sums[i][j] means sum of matrix[0][0]...matrix[i][j]
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */


int main() {
    NumMatrix obj(vector<vector<int>> {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
    });

    std::cout << obj.sumRegion(1, 1, 2, 2) << std::endl;    // 28

    std::cout << obj.sumRegion(0, 0, 0, 2) << std::endl;    // 6

    std::cout << obj.sumRegion(0, 1, 0, 2) << std::endl;    // 5

    std::cout << obj.sumRegion(0, 0, 2, 0) << std::endl;    // 12

    std::cout << obj.sumRegion(1, 0, 2, 0) << std::endl;    // 11

    std::cout << obj.sumRegion(0, 1, 1, 2) << std::endl;    // 16

    std::cout << obj.sumRegion(1, 0, 2, 1) << std::endl;    // 24


    std::cout << "================================" << std::endl;


    obj = NumMatrix(vector<vector<int>> {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    });

    std::cout << obj.sumRegion(2, 1, 4, 3) << std::endl;    // 8

    std::cout << obj.sumRegion(1, 1, 2, 2) << std::endl;    // 11

    std::cout << obj.sumRegion(1, 2, 2, 4) << std::endl;    // 12

    return 0;
}
