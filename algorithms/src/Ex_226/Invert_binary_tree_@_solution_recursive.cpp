#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        TreeNode *it = root;
        if (it == nullptr) {
            return it;
        }

        TreeNode *temp = it->left;
        it->left = it->right;
        it->right = temp;

        invertTree(it->left);
        invertTree(it->right);
        
        return it;
    }
};


int main() {
    Solution s;
    TreeNode a1(4), a2(2), a3(7), a4(1), a5(3), a6(6), a7(9);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;
    s.invertTree(&a1);

    std::cout << a1.val
              << "," << a1.left->val << "," << a1.right->val
              << "," << a1.left->left->val << "," << a1.left->right->val
              << "," << a1.right->left->val << "," << a1.right->right->val
              << std::endl;

    return 0;
}
