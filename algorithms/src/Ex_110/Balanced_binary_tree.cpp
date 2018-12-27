#include <iostream>
#include <map>

using std::map;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }

        map<TreeNode *, int> nodes_height;
        calculateHeight(root, nodes_height);
        return isBalanced(root, nodes_height);
    }

private:
    bool isBalanced(TreeNode *root, map<TreeNode *, int> nodes_height) {
        if (root &&
            std::abs(
                    nodes_height[root->left]
                    - nodes_height[root->right]) <= 1) {
            return isBalanced(root->left, nodes_height)
                   && isBalanced(root->right, nodes_height);
        } else if (!root) {
            return true;
        } else {
            return false;
        }
    }

    void calculateHeight(TreeNode *p, map<TreeNode *, int> &nodes_height) {
        if (!p) {
            return;
        }
        nodes_height[p] = height(p);
        calculateHeight(p->left, nodes_height);
        calculateHeight(p->right, nodes_height);
    }

    int height(TreeNode *p) {
        if (!p) {
            return 0;
        }
        int heightL = height(p->left);
        int heightR = height(p->right);
        return heightL > heightR ? heightL + 1 : heightR + 1;
    }
};


int main() {
    Solution s;
    TreeNode a1(3), a2(9), a3(20), a4(15), a5(7);
    a1.left = &a2;
    a1.right = &a3;
    a3.left = &a4;
    a3.right = &a5;
    std::cout << s.isBalanced(&a1) << std::endl;

    TreeNode b1(1), b2(2), b3(2), b4(3), b5(3), b6(4), b7(4);
    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b4.left = &b6;
    b4.right = &b7;
    std::cout << s.isBalanced(&b1) << std::endl;
    return 0;
}
