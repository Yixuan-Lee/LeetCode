// references:
//      https://leetcode.com/articles/lowest-common-ancestor-of-a-binary-tree/


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * return the lowest common ancestor of node p and node q
     * p and q are different and both values will exist in the binary tree
     * all of the nodes' values will be unique
     *
     * @param root root
     * @param p node p
     * @param q node q
     * @return the lowest common ancestor of node p and node q
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        recurseBinaryTree(root, p, q);

        return ans;
    }

private:
    TreeNode *ans = nullptr;

    bool recurseBinaryTree(TreeNode *root, const TreeNode *p,
            const TreeNode *q) {
        if (root == nullptr) {
            return false;
        }

        bool left = recurseBinaryTree(root->left, p, q);
        bool right = recurseBinaryTree(root->right, p, q);
        bool mid = (root == p) || (root == q);
        // if any of two flags are true, then we have found the LCA of p and q
        if (left + right + mid >= 2) {
            ans = root;
            return true;
        }

        return mid || left || right;
    }
};


int main() {
    Solution s;
    TreeNode a1(3), a2(5), a3(1), a4(6), a5(2), a6(0), a7(8), a8(7), a9(4);
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;
    a5.left = &a8;
    a5.right = &a9;

    std::cout << s.lowestCommonAncestor(&a1, &a2, &a3)->val
              << std::endl;   // 3

    std::cout << s.lowestCommonAncestor(&a1, &a2, &a9)->val
              << std::endl;    // 5

    std::cout << s.lowestCommonAncestor(&a1, &a4, &a6)->val
              << std::endl;    // 3

    return 0;
}
