#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        auto rows = static_cast<int> (matrix.size());
        auto cols = static_cast<int> (matrix[0].size());

        bool found = false;
        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] <= target && matrix[rows - 1][i] >= target) {
                found = binarySearch(matrix, target, i, 0, rows);
            }
            if (found) {
                break;
            }
        }

        return found;
    }

private:
    bool binarySearch(const vector<vector<int>> &matrix, int target, int col,
            int left, int right) {
        while (left <= right) {
            int middle = (left + right) / 2;
            if (matrix[middle][col] == target) {
                return true;
            } else if (matrix[middle][col] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
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

    std::cout << s.searchMatrix(input, 15) << std::endl;    // 1  (time -> nlogn)
    return 0;
}
