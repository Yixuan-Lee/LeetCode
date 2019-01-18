// references:
//      https://leetcode.com/articles/maximal-square/


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }

        auto rows = static_cast<int> (matrix.size());
        auto cols = static_cast<int> (matrix[0].size());
        int max = 0;
        int square = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    square = 1;
                    bool stop = false;
                    while (square + i < rows && square + j < cols && !stop) {
                        for (int k = i; k <= square + i; k++) {
                            if (matrix[k][j + square] == '0') {
                                stop = true;
                                break;
                            }
                        }
                        for (int k = j; k <= square + j; k++) {
                            if (matrix[i + square][k] == '0') {
                                stop = true;
                                break;
                            }
                        }
                        if (!stop) {
                            // expand the testing square length until stop sign is true
                            square++;
                        }
                    }
                    if (square > max) {
                        max = square;
                    }
                }
            }
        }

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
