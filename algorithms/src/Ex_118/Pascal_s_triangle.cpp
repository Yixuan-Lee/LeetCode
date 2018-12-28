#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) {
            return ans;
        }
        ans.push_back(vector<int> {1});
        if (numRows == 1) {
            return ans;
        }
        ans.push_back(vector<int> {1, 1});

        int row = 3;
        while (row <= numRows) {
            vector<int> per;
            // initialize all 1s
            for (int i = 0; i < row; i++) {
                per.push_back(1);
            }

            // update the middle elements
            for (int i = 1; i < row - 1; i++) {
                per[i] = ans[row - 1 - 1][i - 1] + ans[row - 1 - 1][i];
            }
            ans.push_back(per);
            row++;
        }

        return ans;
    }
};


// declare a template for overloading the << operator for vector<vector<<T>>
template<typename T>
std::ostream &operator<<(std::ostream &output, const vector<T> &vec) {
    std::cout << "[" << std::endl;
    for (const vector<int> &v : vec) {
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
    std::cout << s.generate(0) << std::endl;
    std::cout << s.generate(1) << std::endl;
    std::cout << s.generate(2) << std::endl;
    std::cout << s.generate(5) << std::endl;
    std::cout << s.generate(8) << std::endl;
    return 0;
}

