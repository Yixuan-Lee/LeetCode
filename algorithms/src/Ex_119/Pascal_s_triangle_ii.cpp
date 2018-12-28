#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        vector<int> per;
        per.push_back(1);
        ans.push_back(per);
        if (rowIndex == 0) {
            return per;
        }
        per.push_back(1);
        ans.push_back(per);
        if (rowIndex == 1) {
            return per;
        }

        int row = 2;
        while (row <= rowIndex) {
            per.clear();
            // initialize all 1s
            for (int i = 0; i < row + 1; i++) {
                per.push_back(1);
            }
            // update the middle elements
            for (int i = 1; i <= row - 1; i++) {
                per[i] = ans[row - 1][i - 1] + ans[row - 1][i];
            }
            ans.push_back(per);
            row++;
        }
        return per;
    }
};


// declare a template for overloading the << operator for vector<T>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &v) {
    std::cout << "[";
    for (auto &i : v) {
        std::cout << i << ",";
    }
    std::cout << "]" << std::endl;
    return output;
}

int main() {
    Solution s;
    std::cout << s.getRow(0) << std::endl;
    std::cout << s.getRow(1) << std::endl;
    std::cout << s.getRow(2) << std::endl;
    std::cout << s.getRow(3) << std::endl;
    std::cout << s.getRow(4) << std::endl;
    std::cout << s.getRow(5) << std::endl;
    return 0;
}
