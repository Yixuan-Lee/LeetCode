// references:
//      https://leetcode.com/problems/word-search/discuss/27658/Accepted-very-short-Java-solution.-No-additional-space.


#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        auto m = static_cast<int> (board.size());
        auto n = static_cast<int> (board[0].size());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (exist(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool exist(vector<vector<char>> &board, int x, int y, string word,
            int currLen) {
        if (currLen == word.length()) {
            return true;
        }

        if (x < 0 || y < 0 || x == board.size() || y == board[0].size()) {
            return false;
        }
        if (board[x][y] != word[currLen]) {
            return false;
        }

        // XOR operation is used for checking if this position has been visited
        // this can be achieved by creating a new array called "visited"
//        board[x][y] ^= 256;
        board[x][y] = '\0'; // removes the letter from the dictionary

        bool isExist = exist(board, x + 1, y, word, currLen + 1)
                       || exist(board, x - 1, y, word, currLen + 1)
                       || exist(board, x, y + 1, word, currLen + 1)
                       || exist(board, x, y - 1, word, currLen + 1);
        // reset
//        board[x][y] ^= 256;
        board[x][y] = word[currLen];

        return isExist;
    }
};


int main() {
    Solution s;
//    vector<vector<char>> board {
//            {'A', 'B', 'C', 'E'},
//            {'S', 'F', 'C', 'S'},
//            {'A', 'D', 'E', 'E'}
//    };
    vector<vector<char>> board {
            {'A', 'A'}
    };
    std::cout << s.exist(board, "AAA") << std::endl;
    return 0;
}

