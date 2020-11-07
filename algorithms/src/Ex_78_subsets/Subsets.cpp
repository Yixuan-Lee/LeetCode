#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) {
            return res;
        }
        auto size = static_cast<int>(nums.size());
        vector<int> per;
        for (int i = 0; i <= size; i++) {
            backtracking(nums, per, i, 0);
            per.clear();
        }

        return res;
    }

private:
    vector<vector<int>> res;

    void
    backtracking(vector<int> &nums, vector<int> per, int length, int curr) {
        if (per.size() == length) {
            res.push_back(per);
            return;
        }
        for (int i = curr; i < nums.size(); i++) {
            per.push_back(nums[i]);
            backtracking(nums, per, length, i + 1);
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
    vector<int> input {1, 2, 3, 4};
    std::cout << s.subsets(input) << std::endl;
    return 0;
}