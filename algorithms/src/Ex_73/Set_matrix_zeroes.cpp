#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        // keeps a record of rows which need to be set to zero
        set<int> rows2Zeroes;
        // keeps a record of columns which need to be set to zero
        set<int> columns2Zeroes;

        auto m = static_cast<int> (matrix.size());
        auto n = static_cast<int> (matrix[0].size());
        // traverse the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    rows2Zeroes.insert(i);
                    columns2Zeroes.insert(j);
                }
            }
        }

        // set corresponding rows to zeroes
        for (set<int>::iterator it = rows2Zeroes.begin();
             it != rows2Zeroes.end(); it++) {
            for (int j = 0; j < n; j++) {
                matrix[*it][j] = 0;
            }
        }

        // set corresponding columns to zeroes
        for (set<int>::iterator it = columns2Zeroes.begin();
             it != columns2Zeroes.end(); it++) {
            for (int i = 0; i < m; i++) {
                matrix[i][*it] = 0;
            }
        }
    }
};


// declare a template for overloading the << operator for vector<vector<<T>>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &vec) {
    std::cout << "[" << std::endl;
    for (const vector<int> &v : vec) {
        std::cout << "\t[";
        for (const auto &i : v) {
            std::cout << i << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
//    vector<vector<int>> matrix {
//            {0, 1, 2, 0},
//            {3, 4, 5, 2},
//            {1, 3, 1, 5}
//    };
    vector<vector<int>> matrix {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
    };
    s.setZeroes(matrix);
    std::cout << matrix << std::endl;
    return 0;
}