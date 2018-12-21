#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::set;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        auto size = static_cast<int> (nums.size());
        vector<int> per;

        // sort at the beginning to avoid the circumstances of {1,4}, {4,1} in the set
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i <= size; i++) {
            backtracking(nums, per, i, 0);
            per.clear();
        }

        for (const vector<int> &v : ansSet) {
            ans.push_back(v);
        }
        return ans;
    }

private:
    vector<vector<int>> ans;
    set<vector<int>> ansSet;

    void backtracking(const vector<int> &nums, vector<int> &per,
            int length, int curr) {
        if (per.size() == length) {
            // remove the duplicates elements
//            std::sort(per.begin(), per.end());
//            per.erase(std::unique(per.begin(), per.end()), per.end());
            ansSet.insert(per);
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
    vector<int> input {4, 4, 4, 1, 4};
    vector<vector<int>> res = s.subsetsWithDup(input);
    std::cout << res << std::endl;
    return 0;
}
