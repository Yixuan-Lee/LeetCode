#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }
        if (!root->left && !root->right && sum == root->val) {
            // if the root is a leaf node and the left sum is equal to
            // the value of the node, then return true
            return true;
        }
        return hasPathSum(root->left, sum - root->val)
               || hasPathSum(root->right, sum - root->val);
    }
};


int main() {
    Solution s;
    TreeNode a1(5), a2(4), a3(8), a4(11), a5(13), a6(4), a7(7), a8(2), a9(1);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a3.left = &a5;
    a3.right = &a6;
    a4.left = &a7;
    a4.right = &a8;
    a6.right = &a9;
    int sum = 22;
    std::cout << s.hasPathSum(&a1, sum) << std::endl;
    sum = 23;
    std::cout << s.hasPathSum(&a1, sum) << std::endl;

    TreeNode b1(1), b2(2);
    b1.left = &b2;
    sum = 1;
    std::cout << s.hasPathSum(&b1, sum) << std::endl;

    TreeNode c1(-2), c2(-3);
    c1.right = &c2;
    sum = -5;
    std::cout << s.hasPathSum(&c1, sum) << std::endl;

    TreeNode d1(1), d2(-2), d3(-3), d4(1), d5(3), d6(-2), d7(-1);
    d1.left = &d2;
    d1.right = &d3;
    d2.left = &d4;
    d2.right = &d5;
    d3.left = &d6;
    d4.left = &d7;
    sum = -1;
    std::cout << s.hasPathSum(&d1, sum) << std::endl;

    return 0;
}
