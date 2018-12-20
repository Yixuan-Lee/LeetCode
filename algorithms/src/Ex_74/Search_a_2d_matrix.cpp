#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        auto m = static_cast<int> (matrix.size());
        auto n = static_cast<int> (matrix[0].size());


        // identify which row may contain the target number
        int targetRow = -1;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] <= target && matrix[i][n - 1] >= target) {
                targetRow = i;
                break;
            }
        }

        // if the target is smaller than the [0][0] or bigger than [m-1][n-1]
        if (targetRow == -1) {
            return false;
        }

        // perform binary search at the target row
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[targetRow][mid] == target) {
                return true;
            } else if (matrix[targetRow][mid] > target) {
                // search at the left part
                right = mid - 1;
            } else if (matrix[targetRow][mid] < target) {
                // search at the right part
                left = mid + 1;
            }
        }

        return false;
    }
};


int main() {
    Solution s;
//    vector<vector<int>> input {
//            {1,  3,  5,  7},
//            {10, 11, 16, 20},
//            {23, 30, 34, 50}
//    };
    vector<vector<int>> input {
            {}
    };
    std::cout << s.searchMatrix(input, 100) << std::endl;
    return 0;
}
