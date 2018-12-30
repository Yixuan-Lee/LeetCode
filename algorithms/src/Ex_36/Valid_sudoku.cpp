// references:
//      https://www.quora.com/Are-HashTables-and-HashMaps-available-in-C++-STL#
//      http://www.cplusplus.com/forum/beginner/218795/
//      http://www.cplusplus.com/reference/unordered_map/unordered_map/count/
//      https://leetcode.com/problems/valid-sudoku/discuss/194269/C%2B%2B-12ms-96.89
//      http://www.cplusplus.com/reference/cstring/memset/
//      https://en.cppreference.com/w/cpp/utility/pair/make_pair
//      https://stackoverflow.com/questions/42759734/whats-the-efficient-way-to-count-duplicates-of-each-pair-of-a-vector
//      https://stackoverflow.com/questions/17663186/initializing-a-two-dimensional-stdvector


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::vector;
using std::string;
// the equivalent of HashMap is std::unordered_map
using std::pair;
using std::unordered_map;

class Solution {
public:
    bool checkRow(int r) {
        unordered_map<char, int> row;
        for (int i = 0; i < 9; i++) {
            if (b[r][i] == '.') {
                continue;
            }
            if (row.count(b[r][i]) == 1) {
                return false;
            }
            row.insert(std::make_pair(b[r][i], r));
        }
        return true;
    }

    bool checkColumn(int c) {
        unordered_map<char, int> col;
        for (int i = 0; i < 9; i++) {
            if (b[i][c] == '.') {
                continue;
            }
            if (col.count(b[i][c]) == 1) {
                return false;
            }
            col.insert(std::make_pair(b[i][c], c));
        }
        return true;
    }

    bool checkBox(int r, int c) {
        int dummy[10];
        // initialize the dummy array (there should be 10, not 9, because index 0 is useless)
        memset(dummy, 0, 10 * sizeof(int));
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (b[i][j] == '.') {
                    continue;
                }
                if (dummy[b[i][j] - '0'] == 0) {
                    dummy[b[i][j] - '0']++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board) {
        if (board.size() != 9) {
            return false;
        }
        this->b = board;

        for (int i = 0; i < 9; i += 3) {
            if (!checkRow(i) || !checkColumn(i)) {
                return false;
            }
            if (!checkRow(i + 1) || !checkColumn(i + 1)) {
                return false;
            }
            if (!checkRow(i + 2) || !checkColumn(i + 2)) {
                return false;
            }
            // check the box
            for (int j = 0; j < 9; j += 3) {
//                std::cout << !checkBox(i, j) << std::endl;
                if (!checkBox(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    vector<vector<char>> b;
};


int main() {
    Solution s;
    vector<vector<char>> vec1 {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> vec2 {
            {'9', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::cout << s.isValidSudoku(vec1) << std::endl;
    std::cout << s.isValidSudoku(vec2) << std::endl;

    return 0;
}
