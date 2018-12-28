#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (!root) {
            return ans;
        }
        if (!root->left && !root->right && root->val == sum) {
            per.push_back(root->val);
            ans.push_back(per);
            per.pop_back();
            return ans;
        }
        per.push_back(root->val);
        // go left
        ans = pathSum(root->left, sum - root->val);
        // go right
        ans = pathSum(root->right, sum - root->val);
        // backtrack
        per.pop_back();
        return ans;
    }

private:
    vector<vector<int>> ans;

    vector<int> per;
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
    TreeNode a1(5), a2(4), a3(8), a4(11), a5(13);
    TreeNode a6(4), a7(7), a8(2), a9(5), a10(1);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a3.left = &a5;
    a3.right = &a6;
    a4.left = &a7;
    a4.right = &a8;
    a6.left = &a9;
    a6.right = &a10;

    vector<vector<int>> res = s.pathSum(&a1, 22);
    std::cout << res << std::endl;
    return 0;
}

