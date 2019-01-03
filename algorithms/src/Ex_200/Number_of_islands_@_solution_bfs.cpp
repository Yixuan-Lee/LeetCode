// references:
//      https://leetcode.com/problems/number-of-islands/discuss/56338/Java-DFS-and-BFS-solution


#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

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
                    bfs(grid, i, j);
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

    void bfs(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        // the queue records the nodes that we have visited in the current traversal
        queue<int> que;
        // the code is the index of the node we are currently visiting, so we know
        // where we are going to backtrack
        int code = i * cols + j;
        que.push(code);
        while (!que.empty()) {
            code = que.front();
            que.pop();
            int rowNum = code / cols;
            int colNum = code % cols;
            if (rowNum > 0
                && grid[rowNum - 1][colNum] == '1') {       // up
                que.push((rowNum - 1) * cols + colNum);
                grid[rowNum - 1][colNum] = '0';
            }
            if (rowNum < rows - 1
                && grid[rowNum + 1][colNum] == '1') {       // down
                que.push((rowNum + 1) * cols + colNum);
                grid[rowNum + 1][colNum] = '0';
            }
            if (colNum > 0
                && grid[rowNum][colNum - 1] == '1') {       // left
                que.push(rowNum * cols + (colNum - 1));
                grid[rowNum][colNum - 1] = '0';
            }
            if (colNum < cols - 1
                && grid[rowNum][colNum + 1] == '1') {       // right
                que.push(rowNum * cols + (colNum + 1));
                grid[rowNum][colNum + 1] = '0';
            }
        }
    }
};


int main() {
    Solution s {};
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
