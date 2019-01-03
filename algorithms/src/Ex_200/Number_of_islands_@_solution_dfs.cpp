// references:
//      https://leetcode.com/problems/number-of-islands/discuss/56338/Java-DFS-and-BFS-solution


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }

        islands = 0;
        rows = static_cast<int> (grid.size());
        cols = static_cast<int> (grid[0].size());

        if (rows == 1) {
            // only 1 row
            for (int i = 0; i < cols; i++) {
                if (grid[0][i] == '1') {
                    islands++;
                    int j;
                    for (j = i + 1; j < cols && grid[0][j] == '1'; j++) {
                    }
                    i = j;
                }
            }
            return islands;
        }
        if (cols == 1) {
            // only 1 column
            for (int i = 0; i < rows; i++) {
                if (grid[i][0] == '1') {
                    islands++;
                    int j;
                    for (j = i + 1; j < rows && grid[j][0] == '1'; j++) {
                    }
                    i = j;
                }
            }
            return islands;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }

private:
    int islands;
    int rows;
    int cols;

    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || i >= rows) {
            return;
        }
        if (j < 0 || j >= cols) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';

        dfs(grid, i - 1, j);    // up
        dfs(grid, i + 1, j);    // down
        dfs(grid, i, j - 1);    // left
        dfs(grid, i, j + 1);    // right
    }
};


int main() {
    Solution s;
    vector<vector<char>> input;

    input = vector<vector<char>> {
            {'1', '1', '0', '1', '0', '1', '1'}
    };
    std::cout << s.numIslands(input) << std::endl;      // 3

    input = vector<vector<char>> {
            {'1'},
            {'1'},
            {'0'},
            {'1'},
            {'0'},
            {'1'},
            {'0'},
            {'1'}
    };
    std::cout << s.numIslands(input) << std::endl;      // 4

    input = vector<vector<char>> {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
            {'1', '1', '0', '1', '0'},
            {'1', '0', '1', '0', '1'},
    };
    std::cout << s.numIslands(input) << std::endl;      // 6

    return 0;
}
