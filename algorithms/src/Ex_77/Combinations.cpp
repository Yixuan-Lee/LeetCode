#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k) {
            return res;
        }

        vector<int> per;
        backtracking(per, n, k, 0);
        return res;
    }

private:
    vector<vector<int>> res;

    void backtracking(vector<int> per, int n, int k, int curr) {
        if (per.size() == k) {
            res.push_back(per);
            return;
        }
        for (int i = curr + 1; i <= n; i++) {
            per.push_back(i);
            backtracking(per, n, k, i);
            per.pop_back();
        }
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
    std::cout << s.combine(8, 4) << std::endl;
    return 0;
}