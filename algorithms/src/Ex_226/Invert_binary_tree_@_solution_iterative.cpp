// references:
//      Ex_144: Binary tree preorder traversal
//      https://leetcode.com/problems/invert-binary-tree/submissions/


#include <iostream>
#include <stack>

using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }

        stack<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            TreeNode *curr = nodes.top();
            nodes.pop();
            TreeNode *temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            if (curr->left) {
                nodes.push(curr->left);
            }
            if (curr->right) {
                nodes.push(curr->right);
            }
        }

        return root;
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
              << std::endl;     // [4, 7, 2, 9, 6, 3, 1]

    TreeNode b1(1), b2(2);
    b1.right = &b2;
    s.invertTree(&b1);
    std::cout << b1.val << "," << b1.left->val << std::endl;    // [1, 2]

    TreeNode c1(3), c2(1), c3(2);
    c1.right = &c2;
    c2.left = &c3;
    s.invertTree(&c1);
    std::cout << c1.val << "," << c1.left->val << "," << c1.left->right->val
              << std::endl;   // [3, 1, 2]

    return 0;
}
