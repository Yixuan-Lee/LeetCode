#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        auto rows = static_cast<int> (board.size());
        auto cols = static_cast<int> (board[0].size());

        vector<vector<int>> ans(rows, vector<int>(cols, 0));
        if (rows == 0 && cols == 0) {
            board = ans;
            return;
        }
        if (rows == 1 && cols == 1) {
            board = ans;
            return;
        }
        if (rows == 1) {
            board = ans;
            return;
        }
        if (cols == 1) {
            board = ans;
            return;;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int capacity =
                        numberOfOnesInHorizontal(board, i, j, rows, cols)
                        + numberOfOnesInVertical(board, i, j, rows, cols)
                        + numberOfOnesInTwoDiagonals(board, i, j, rows, cols);
                if (board[i][j] == 1 && capacity < 2) {
                    ans[i][j] = 0;
                } else if (board[i][j] == 1
                           && (capacity == 2 || capacity == 3)) {
                    ans[i][j] = 1;
                } else if (board[i][j] == 1 && capacity > 3) {
                    ans[i][j] = 0;
                } else if (board[i][j] == 0 && capacity == 3) {
                    ans[i][j] = 1;
                }
            }
        }

        board = ans;
    }

private:
    int numberOfOnesInVertical(const vector<vector<int>> &board,
            int x, int y, int rows, int cols) {
        if (x - 1 < 0) {
            return board[x + 1][y];
        }
        if (x + 1 >= rows) {
            return board[x - 1][y];
        }

        return board[x + 1][y] + board[x - 1][y];
    }

    int numberOfOnesInHorizontal(const vector<vector<int>> &board,
            int x, int y, int rows, int cols) {
        if (y - 1 < 0) {
            return board[x][y + 1];
        }
        if (y + 1 >= cols) {
            return board[x][y - 1];
        }

        return board[x][y + 1] + board[x][y - 1];
    }

    int numberOfOnesInTwoDiagonals(const vector<vector<int>> &board,
            int x, int y, int rows, int cols) {
        if (x == 0 && y == 0) {
            return board[x + 1][y + 1];
        }
        if (x == 0 && y == cols - 1) {
            return board[x + 1][y - 1];
        }
        if (x == 0) {
            return board[x + 1][y - 1] + board[x + 1][y + 1];
        }
        if (x == rows - 1 && y == 0) {
            return board[x - 1][y + 1];
        }
        if (x == rows - 1 && y == cols - 1) {
            return board[x - 1][y - 1];
        }
        if (x == rows - 1) {
            return board[x - 1][y + 1] + board[x - 1][y - 1];
        }
        if (y == 0) {
            return board[x + 1][y + 1] + board[x - 1][y + 1];
        }
        if (y == cols - 1) {
            return board[x + 1][y - 1] + board[x - 1][y - 1];
        }

        return board[x - 1][y - 1] + board[x - 1][y + 1] + board[x + 1][y - 1]
               + board[x + 1][y + 1];
    }
};


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

int main() {
    Solution s;
    vector<vector<int>> input {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
    };
    s.gameOfLife(input);
    std::cout << input << std::endl;
    // [
    //      [0, 0, 0],
    //      [1, 0, 1],
    //      [0, 1, 1],
    //      [0, 1, 0]
    // ]

    input = vector<vector<int>> {
            {0}
    };
    s.gameOfLife(input);
    std::cout << input << std::endl;
    // [
    //      [0]
    // ]

    input = vector<vector<int>> {
            {0, 1, 1, 0, 1, 0}
    };
    s.gameOfLife(input);
    std::cout << input << std::endl;
    // [
    //      [0, 0, 0, 0, 0, 0]
    // ]

    input = vector<vector<int>> {
            {0},
            {1},
            {1},
            {0},
            {1},
            {0}
    };
    s.gameOfLife(input);
    std::cout << input << std::endl;
    // [
    //      [0],
    //      [0],
    //      [0],
    //      [0],
    //      [0],
    //      [0],
    // ]

    input = vector<vector<int>> {
            {0, 1},
            {1, 1}
    };
    s.gameOfLife(input);
    std::cout << input << std::endl;
    // [
    //      [1, 1],
    //      [1, 1]
    // ]

    input = vector<vector<int>> {
            {0, 1},
            {1, 0}
    };
    s.gameOfLife(input);
    std::cout << input << std::endl;
    // [
    //      [0, 0],
    //      [0, 0]
    // ]

    return 0;
}
