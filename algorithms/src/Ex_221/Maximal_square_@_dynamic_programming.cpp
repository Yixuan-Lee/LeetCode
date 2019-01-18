#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

// declare a template for overloading the << operator for vector<vector<<T>>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<vector<T>> &vec) {
    std::cout << "[" << std::endl;
    for (const vector<T> &v : vec) {
        std::cout << "\t[";
        for (const auto &i : v) {
            std::cout << i << ", ";
        }
        std::cout << "]" << std::endl;
    }
    std::cout << "]" << std::endl;
    return output;
}

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        vector<vector<int>> dp;
        int max = -1;
        auto rows = static_cast<int> (matrix.size());
        auto cols = static_cast<int> (matrix[0].size());
        dp.reserve(static_cast<unsigned long>(rows));
        for (int i = 0; i < rows; i++) {
            dp.emplace_back(cols, 0);
        }
        for (int i = 0; i < rows; i++) {
            dp[i][0] = (matrix[i][0] == '1') ? 1 : 0;
            if (dp[i][0] > max) {
                max = dp[i][0];
            }
        }
        for (int i = 1; i < cols; i++) {
            dp[0][i] = (matrix[0][i] == '1') ? 1 : 0;
            if (dp[0][i] > max) {
                max = dp[0][i];
            }
        }

        // for debugging
//        std::cout << dp << std::endl;
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]),
                            dp[i - 1][j - 1]) + 1;
                    if (dp[i][j] > max) {
                        max = dp[i][j];
                    }
                }
            }
        }
        // for debugging
//        std::cout << dp << std::endl;

        return max * max;
    }
};


int main() {
    Solution s;
    vector<vector<char>> matrix {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'},
    };
    std::cout << s.maximalSquare(matrix) << std::endl;      // 4

    matrix = vector<vector<char>> {
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '1', '1', '1'},
    };
    std::cout << s.maximalSquare(matrix) << std::endl;      // 9

    matrix = vector<vector<char>> {
            {'1'}
    };
    std::cout << s.maximalSquare(matrix) << std::endl;      // 1

    matrix = vector<vector<char>> {
            {'1', '1'}
    };
    std::cout << s.maximalSquare(matrix) << std::endl;      // 1

    return 0;
}
