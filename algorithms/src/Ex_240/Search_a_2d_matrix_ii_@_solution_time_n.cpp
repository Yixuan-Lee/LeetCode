// references:
//      https://leetcode.com/submissions/detail/202251031/  (sample 40ms submission)


#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        auto row = static_cast<int> (matrix.size() - 1);
        int col = 0;

        // search start from left bottom to right top
        while (row >= 0 && col < matrix[row].size()) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                row--;
            } else {
                col++;
            }
        }

        return false;
    }
};


int main() {
    Solution s;
    vector<vector<int>> input {
            {1,  4,  7,  11, 15},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    std::cout << s.searchMatrix(input, 5) << std::endl;     // 1
    std::cout << s.searchMatrix(input, 20) << std::endl;    // 0

    std::cout << s.searchMatrix(input, 23) << std::endl;    // 1
    std::cout << s.searchMatrix(input, 25) << std::endl;    // 0

    std::cout << s.searchMatrix(input, 15)
              << std::endl;    // 1  (time -> nlogn)
    return 0;
}
