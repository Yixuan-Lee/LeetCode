#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        if (root == nullptr) {
            return vector<string> {};
        }

        vector<string> ans;
        vector<int> per;
        dfs(root, per, ans);

        return ans;
    }

private:
    void dfs(TreeNode *p, vector<int> &per, vector<string> &ans) {
        if (p == nullptr) {
            return;
        }

        per.push_back(p->val);
        if (p->left == nullptr && p->right == nullptr) {
            string str = "";
            for (int i = 0; i < per.size() - 1; i++) {
                str += std::to_string(per[i]) + "->";
            }
            str += std::to_string(per[per.size() - 1]);
            ans.push_back(str);
            // pop before returning
            per.pop_back();
            return;
        }

        dfs(p->left, per, ans);
        dfs(p->right, per, ans);
        // pop before returning
        per.pop_back();
        return;
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

    TreeNode a1(1), a2(2), a3(3), a4(5);
    a1.left = &a2;
    a1.right = &a3;
    a2.right = &a4;
    std::cout << s.binaryTreePaths(&a1) << std::endl;   // ["1->2->5", "1->3"]

    return 0;
}
