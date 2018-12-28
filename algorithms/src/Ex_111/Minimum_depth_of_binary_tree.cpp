#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int minL = INT32_MAX;
        int minR = INT32_MAX;
        if (root->left) {
            // have no left child
            minL = minDepth(root->left);
        }
        if (root->right) {
            // have no right child
            minR = minDepth(root->right);
        }
        return std::min(minL, minR) + 1;
    }
};


int main() {
    Solution s;
    TreeNode a1(3), a2(9), a3(20), a4(15), a5(7);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;
    std::cout << s.minDepth(&a1) << std::endl;

    TreeNode b1(1), b2(2), b3(2), b4(3), b5(3), b6(4), b7(4);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b4.left = &b6;
    b4.right = &b7;
    std::cout << s.minDepth(&b1) << std::endl;

    TreeNode c1(1), c2(2);
    c1.left = &c2;
    std::cout << s.minDepth(&c1) << std::endl;
    return 0;
}
