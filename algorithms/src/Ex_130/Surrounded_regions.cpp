// references:
//      https://leetcode.com/problems/surrounded-regions/discuss/41612/A-really-simple-and-readable-C%2B%2B-solutionuff0conly-cost-12ms


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty()) {
            return;
        }
        if (board.size() == 1) {
            // only 1 row
            return;
        }
        if (board[0].size() == 1) {
            // only 1 column
            return;
        }

        auto rows = static_cast<int> (board.size());
        auto cols = static_cast<int> (board[0].size());

        for (int i = 0; i < rows; i++) {
            check(board, i, 0, rows, cols);
            if (cols > 1) {
                check(board, i, cols - 1, rows, cols);
            }
        }
        for (int j = 1; j < cols - 1; j++) {
            check(board, 0, j, rows, cols);
            if (rows > 1) {
                check(board, rows - 1, j, rows, cols);
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
            }
        }

    }

private:
    void check(vector<vector<char>> &board, int i, int j,
            int rows, int cols) {
        if (board[i][j] == 'O') {
            board[i][j] = '1';
            if (i > 1) {
                // check left
                check(board, i - 1, j, rows, cols);
            }
            if (j > 1) {
                // check up
                check(board, i, j - 1, rows, cols);
            }
            if (i + 1 < rows) {
                // check down
                check(board, i + 1, j, rows, cols);
            }
            if (j + 1 < cols) {
                // check right
                check(board, i, j + 1, rows, cols);
            }
        }
    }
};


int main() {
    Solution s;
    vector<vector<char>> input {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'X', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
    };
    s.solve(input);
    for (auto &i : input) {
        for (char j : i) {
            std::cout << j << ',';
        }
        std::cout << std::endl;
    }
    return 0;
}
