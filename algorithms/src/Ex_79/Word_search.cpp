// references:
//      https://stackoverflow.com/questions/936687/how-do-i-declare-a-2d-array-in-c-using-new


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        m = static_cast<int> (board.size());
        n = static_cast<int> (board[0].size());

        string per;
        bool **used = new bool *[m];
        for (int i = 0; i < m; i++) {
            used[i] = new bool[n];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isExist) {
                    std::cout << "isExist = " << isExist << std::endl;
                    return isExist;
                }
                if (board[i][j] == word[0]) {
                    isExist = false;
                    dfs(board, used, per, word, i, j, 0);
                    initialize(used, m, n);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            delete[] used[i];
        }
        delete[] used;

        std::cout << "isExist = " << isExist << std::endl;
        return isExist;
    }

private:
    bool isExist;
    int m;
    int n;

    void dfs(const vector<vector<char>> &board, bool **used, string per,
            string word, int x, int y, int curr) {
        if (isExist) {
            return;
        }
        if (per == word) {
            isExist = true;
            return;
        }
        if (x < 0 || y < 0 || x == m || y == n) {
            return;
        }
        if (used[x][y]) {
            return;
        }
        if (word[curr] != board[x][y]) {
            return;
        }
        per.push_back(board[x][y]);
        used[x][y] = true;

        // go up
        dfs(board, used, per, word, x - 1, y, curr + 1);
        // go down
        dfs(board, used, per, word, x + 1, y, curr + 1);
        // go left
        dfs(board, used, per, word, x, y - 1, curr + 1);
        // go right
        dfs(board, used, per, word, x, y + 1, curr + 1);

        // backtracking
        used[x][y] = false;
    }

    void initialize(bool **used, int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                used[i][j] = false;
            }
        }
    }
};


int main() {
    Solution s;
    vector<vector<char>> board {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
//    vector<vector<char>> board {
//            {'A', 'A'}
//    };
    std::cout << s.exist(board, "ABCCED") << std::endl;
    return 0;
}

